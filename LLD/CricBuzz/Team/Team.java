package CricBuzz.Team;

import java.util.List;
import java.util.Queue;

import CricBuzz.Team.Player.PlayerBattingController;
import CricBuzz.Team.Player.PlayerBowlingController;
import CricBuzz.Team.Player.PlayerDetails;

public class Team {
    public final String teamName;
    public final Queue<PlayerDetails> playing11;
    public final List<PlayerDetails> bench;
    public final PlayerBattingController battingController;
    public final PlayerBowlingController bowlingController;
    public boolean isWinner;

    public Team(String teamName, Queue<PlayerDetails> playing11, List<PlayerDetails> bench,
            List<PlayerDetails> bowlers) {
        this.teamName = teamName;
        this.playing11 = playing11;
        this.bench = bench;
        this.battingController = new PlayerBattingController(playing11);
        this.bowlingController = new PlayerBowlingController(bowlers);
    }

    public String getTeamName() {
        return teamName;
    }

    public void chooseNextBatsman() throws Exception{
        battingController.getNextBatsman(); 
    }

    public void chooseNextBowler(int maxOverCountPerBowler) {
        bowlingController.getNextBowler(maxOverCountPerBowler);
    }

    public PlayerDetails getStriker(){
        return battingController.getStriker();
    }

    public void setStriker(PlayerDetails player) {
        battingController.setStriker(player);
    }

    public PlayerDetails getNonStriker() {
        return battingController.getNonStriker();
    }

    public void setNonStriker(PlayerDetails player) {
        battingController.setNonStriker(player);
    }

    public PlayerDetails getCurrentBowler() {
        return bowlingController.getCurrentBowler();
    }

    public void printBattingScoreCard() {
        System.out.println("----------------------------------------------------------------");
        System.out.printf("%-14s %5s %5s %4s %4s %8s %-12s%n",
                "Player", "Runs", "Balls", "4s", "6s", "RunRate", "Wicket");
        System.out.println("----------------------------------------------------------------");
        for (PlayerDetails playerDetails : playing11) {
            playerDetails.printBattingScoreCard();
        }
        System.out.println("----------------------------------------------------------------");
    }

    public void printBowlingScoreCard() {
        System.out.println("------------------------------------------------------------");
        System.out.printf("%-14s %5s %5s %5s %4s %4s %8s%n",
                "Player", "Overs", "Runs", "Wkts", "NB", "WB", "Economy");
        System.out.println("------------------------------------------------------------");
        boolean hasBowlingStats = false;
        for (PlayerDetails playerDetails : playing11) {
            if (playerDetails.bowlingScoreCard.totalOversCount > 0) {
                hasBowlingStats = true;
                playerDetails.printBowlingScoreCard();
            }
        }
        if (!hasBowlingStats) {
            System.out.println("No bowling stats available.");
        }
        System.out.println("------------------------------------------------------------");
    }

    public int getTotalRuns() {
        int totalRun = 0;
        for (PlayerDetails player : playing11) {
            totalRun += player.battingScoreCard.totalRunsScored;
        }
        return totalRun;
    }

    public void swapStrikers() {
        PlayerDetails temp = battingController.getStriker();
        battingController.setStriker(battingController.getNonStriker());
        battingController.setNonStriker(temp);
    }
}
