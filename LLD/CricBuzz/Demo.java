package CricBuzz;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.file.Files;
import java.nio.file.StandardOpenOption;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.LocalDate;
import java.time.ZoneId;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Queue;

import CricBuzz.Team.Team;
import CricBuzz.Team.Player.Person;
import CricBuzz.Team.Player.PlayerDetails;
import CricBuzz.Team.Player.PlayerType;

public class Demo {

	private static final String DEFAULT_INPUT_FILE = "CricBuzz/input.txt";
	private static final String DEFAULT_LOGS_FILE = "CricBuzz/logs.txt";
	private static final String DEFAULT_OUTPUT_FILE = "CricBuzz/output.txt";

	private static Team teamA;
	private static Team teamB;
	private static Match match;
	private static boolean matchStarted;

	public static void main(String[] args) {
		String inputFilePath = args.length > 0 ? args[0] : DEFAULT_INPUT_FILE;
		String logsFilePath = args.length > 1 ? args[1] : DEFAULT_LOGS_FILE;
		String outputFilePath = args.length > 2 ? args[2] : DEFAULT_OUTPUT_FILE;

		Path inputPath = Paths.get(inputFilePath);
		Path logsPath = Paths.get(logsFilePath);
		Path outputPath = Paths.get(outputFilePath);

		if (!Files.exists(inputPath)) {
			System.out.println("Input file not found: " + inputPath.toAbsolutePath());
			return;
		}

		PrintStream originalOut = System.out;
		try {
			if (logsPath.getParent() != null) {
				Files.createDirectories(logsPath.getParent());
			}
			if (outputPath.getParent() != null) {
				Files.createDirectories(outputPath.getParent());
			}

			try (PrintStream fileOut = new PrintStream(
					Files.newOutputStream(outputPath, StandardOpenOption.CREATE,
							StandardOpenOption.TRUNCATE_EXISTING))) {
				System.setOut(fileOut);
				executeMenuFromFile(inputPath, logsPath);
			}
		} catch (Exception e) {
			originalOut.println("Execution failed: " + e.getMessage());
		} finally {
			System.setOut(originalOut);
		}
	}

	private static void executeMenuFromFile(Path inputPath, Path outputPath) throws IOException {
		try (BufferedReader reader = Files.newBufferedReader(inputPath);
				BufferedWriter writer = Files.newBufferedWriter(outputPath)) {

			logLine(writer, "=== CricBuzz Menu Execution Started ===");
			printMenu(writer);

			String line;
			while ((line = reader.readLine()) != null) {
				line = line.trim();

				if (line.isEmpty() || line.startsWith("#")) {
					continue;
				}

				int choice;
				try {
					choice = Integer.parseInt(line);
				} catch (NumberFormatException ex) {
					logLine(writer, "Invalid menu choice: " + line);
					continue;
				}

				Map<String, String> config = new HashMap<>();
				if (choice == 1) {
					config = readConfigBlock(reader, writer);
				}

				if (!executeChoice(choice, config, writer)) {
					break;
				}
			}

			logLine(writer, "=== CricBuzz Menu Execution Finished ===");
		}
	}

	private static Map<String, String> readConfigBlock(BufferedReader reader, BufferedWriter writer)
			throws IOException {
		Map<String, String> config = new HashMap<>();
		logLine(writer, "Reading match configuration block...");

		String line;
		while ((line = reader.readLine()) != null) {
			line = line.trim();
			if (line.isEmpty() || line.startsWith("#")) {
				continue;
			}
			if ("END_CONFIG".equalsIgnoreCase(line)) {
				return config;
			}

			int idx = line.indexOf('=');
			if (idx <= 0 || idx == line.length() - 1) {
				logLine(writer, "Skipping invalid config entry: " + line);
				continue;
			}

			String key = line.substring(0, idx).trim().toUpperCase(Locale.ROOT);
			String value = line.substring(idx + 1).trim();
			config.put(key, value);
		}

		return config;
	}

	private static boolean executeChoice(int choice, Map<String, String> config, BufferedWriter writer) {
		try {
			switch (choice) {
				case 1:
					createMatchFromConfig(config, writer);
					break;
				case 2:
					startMatch(writer);
					break;
				case 3:
					printTeamLineup(writer);
					break;
				case 4:
					printBattingScorecards(writer);
					break;
				case 5:
					printBowlingScorecards(writer);
					break;
				case 6:
					printMatchStatus(writer);
					break;
				case 7:
					printMenu(writer);
					break;
				case 9:
					logLine(writer, "Exit selected. Stopping execution.");
					return false;
				default:
					logLine(writer, "Unsupported menu choice: " + choice);
			}
		} catch (Exception e) {
			logLine(writer, "Error while executing choice " + choice + ": " + e.getMessage());
		}

		return true;
	}

	private static void createMatchFromConfig(Map<String, String> config, BufferedWriter writer) {
		String teamAName = config.getOrDefault("TEAM_A_NAME", "TeamA");
		String teamBName = config.getOrDefault("TEAM_B_NAME", "TeamB");
		String venue = config.getOrDefault("VENUE", "Unknown Venue");
		String matchTypeValue = config.getOrDefault("MATCH_TYPE", "T20");
		String dateValue = config.getOrDefault("MATCH_DATE", "2026-04-02");

		List<String> teamAPlayers = parseCsv(config.getOrDefault("TEAM_A_PLAYERS", defaultPlayers(teamAName)));
		List<String> teamBPlayers = parseCsv(config.getOrDefault("TEAM_B_PLAYERS", defaultPlayers(teamBName)));

		List<String> teamABowlers = parseCsv(
				config.getOrDefault("TEAM_A_BOWLERS", String.join(",", firstN(teamAPlayers, 5))));
		List<String> teamBBowlers = parseCsv(
				config.getOrDefault("TEAM_B_BOWLERS", String.join(",", firstN(teamBPlayers, 5))));

		teamA = buildTeam(teamAName, teamAPlayers, teamABowlers);
		teamB = buildTeam(teamBName, teamBPlayers, teamBBowlers);

		MatchType matchType = "ODI".equalsIgnoreCase(matchTypeValue) ? new OneDayMatch() : new T20Match();

		Date matchDate = Date.from(LocalDate.parse(dateValue, DateTimeFormatter.ISO_DATE)
				.atStartOfDay(ZoneId.systemDefault()).toInstant());

		match = new Match(teamA, teamB, matchDate, venue, null, matchType);
		matchStarted = false;

		logLine(writer, "Match created successfully: " + teamAName + " vs " + teamBName + " at " + venue);
		logLine(writer, "Match Type: " + (matchType instanceof OneDayMatch ? "ODI" : "T20"));
	}

	private static Team buildTeam(String teamName, List<String> players, List<String> bowlers) {
		Queue<PlayerDetails> playing11 = new LinkedList<>();
		List<PlayerDetails> bench = new ArrayList<>();
		List<PlayerDetails> bowlersList = new ArrayList<>();

		for (int i = 0; i < players.size(); i++) {
			String playerName = players.get(i);
			PlayerType type = i < 5 ? PlayerType.ALL_ROUNDER : PlayerType.BATSMAN;
			PlayerDetails player = new PlayerDetails(new Person(playerName, 20 + (i % 10)), type);
			playing11.add(player);
		}

		for (PlayerDetails player : playing11) {
			if (bowlers.contains(player.person.name)) {
				bowlersList.add(player);
			}
		}

		if (bowlersList.isEmpty()) {
			int count = 0;
			for (PlayerDetails player : playing11) {
				bowlersList.add(player);
				count++;
				if (count == 5) {
					break;
				}
			}
		}

		return new Team(teamName, playing11, bench, bowlersList);
	}

	private static void startMatch(BufferedWriter writer) throws Exception {
		if (match == null) {
			logLine(writer, "No match found. Use option 1 to create a match first.");
			return;
		}

		match.startMatch();
		matchStarted = true;
		logLine(writer, "Match simulation completed.");
	}

	private static void printTeamLineup(BufferedWriter writer) {
		if (teamA == null || teamB == null) {
			logLine(writer, "No teams available. Use option 1 first.");
			return;
		}

		logLine(writer, "Team A: " + teamA.teamName);
		for (PlayerDetails player : teamA.playing11) {
			logLine(writer, " - " + player.person.name + " (" + player.playerType + ")");
		}

		logLine(writer, "Team B: " + teamB.teamName);
		for (PlayerDetails player : teamB.playing11) {
			logLine(writer, " - " + player.person.name + " (" + player.playerType + ")");
		}
	}

	private static void printBattingScorecards(BufferedWriter writer) {
		if (teamA == null || teamB == null) {
			logLine(writer, "No teams available. Use option 1 first.");
			return;
		}
		if (!matchStarted) {
			logLine(writer, "Match has not started yet. Use option 2 first.");
			return;
		}

		logLine(writer, "Batting scorecard: " + teamA.teamName);
		teamA.printBattingScoreCard();
		logLine(writer, "Batting scorecard printed to console for " + teamA.teamName);

		logLine(writer, "Batting scorecard: " + teamB.teamName);
		teamB.printBattingScoreCard();
		logLine(writer, "Batting scorecard printed to console for " + teamB.teamName);
	}

	private static void printBowlingScorecards(BufferedWriter writer) {
		if (teamA == null || teamB == null) {
			logLine(writer, "No teams available. Use option 1 first.");
			return;
		}
		if (!matchStarted) {
			logLine(writer, "Match has not started yet. Use option 2 first.");
			return;
		}

		logLine(writer, "Bowling scorecard: " + teamA.teamName);
		teamA.printBowlingScoreCard();
		logLine(writer, "Bowling scorecard printed to console for " + teamA.teamName);

		logLine(writer, "Bowling scorecard: " + teamB.teamName);
		teamB.printBowlingScoreCard();
		logLine(writer, "Bowling scorecard printed to console for " + teamB.teamName);
	}

	private static void printMatchStatus(BufferedWriter writer) {
		if (teamA == null || teamB == null) {
			logLine(writer, "No match context available. Use option 1 first.");
			return;
		}

		if (!matchStarted) {
			logLine(writer, "Match status: Created, not started.");
			return;
		}

		int teamAScore = teamA.getTotalRuns();
		int teamBScore = teamB.getTotalRuns();
		logLine(writer, teamA.teamName + " score: " + teamAScore);
		logLine(writer, teamB.teamName + " score: " + teamBScore);

		if (teamA.isWinner) {
			logLine(writer, "Winner: " + teamA.teamName);
		} else if (teamB.isWinner) {
			logLine(writer, "Winner: " + teamB.teamName);
		} else {
			logLine(writer, "Winner: Match Draw");
		}
	}

	private static List<String> parseCsv(String csv) {
		List<String> result = new ArrayList<>();
		String[] split = csv.split(",");
		for (String item : split) {
			String value = item.trim();
			if (!value.isEmpty()) {
				result.add(value);
			}
		}
		return result;
	}

	private static List<String> firstN(List<String> list, int count) {
		List<String> output = new ArrayList<>();
		for (int i = 0; i < list.size() && i < count; i++) {
			output.add(list.get(i));
		}
		return output;
	}

	private static String defaultPlayers(String teamName) {
		List<String> players = new ArrayList<>();
		for (int i = 1; i <= 11; i++) {
			players.add(teamName + "_P" + i);
		}
		return String.join(",", players);
	}

	private static void printMenu(BufferedWriter writer) throws IOException {
		logLine(writer, "Menu:");
		logLine(writer, "1 -> Create Match (follow with config block and END_CONFIG)");
		logLine(writer, "2 -> Start Match");
		logLine(writer, "3 -> Print Teams Lineup");
		logLine(writer, "4 -> Print Batting Scorecards");
		logLine(writer, "5 -> Print Bowling Scorecards");
		logLine(writer, "6 -> Print Match Status");
		logLine(writer, "7 -> Print Menu Again");
		logLine(writer, "9 -> Exit");
	}

	private static void logLine(BufferedWriter writer, String message) {
		System.out.println(message);
		try {
			writer.write(message);
			writer.newLine();
			writer.flush();
		} catch (IOException e) {
			System.err.println("Failed to write to output file: " + e.getMessage());
		}
	}
}
