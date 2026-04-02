package CricBuzz;

import java.util.Date;

import CricBuzz.Inning.InningDetails;
import CricBuzz.Team.Team;

public class Match {
    Team teamA;
    Team teamB;
    Date matchDate;
    String venue;
    Team tossWinner;
    MatchType matchType;
    InningDetails[] innings;

    public Match(Team teamA, Team teamB, Date matchDate, String venue, Team tossWinner, MatchType matchType) {
        this.teamA = teamA;
        this.teamB = teamB;
        this.matchDate = matchDate;
        this.venue = venue;
        this.matchType = matchType;
        this.innings = new InningDetails[2];
    }

    public void startMatch() throws Exception {
        tossWinner = toss(teamA, teamB);
        System.out.println("Toss Winner: " + tossWinner.getTeamName());

        InningDetails firstInning, secondInning;
        Team battingTeam, bowlingTeam;

        // assuming toss winner always chooses to bat first
        battingTeam = tossWinner;
        bowlingTeam = battingTeam == teamA ? teamB : teamA;

        firstInning = new InningDetails(battingTeam, bowlingTeam, matchType);
        firstInning.start(-1);

        System.out.println();
        System.out.println("INNING " + 1 + " -- total Run: " + battingTeam.getTotalRuns());
        System.out.println("---Batting ScoreCard : " + battingTeam.teamName + "---");
        battingTeam.printBattingScoreCard();

        System.out.println();
        System.out.println("---Bowling ScoreCard : " + bowlingTeam.teamName + "---");
        bowlingTeam.printBowlingScoreCard();

        // switch teams for second inning
        battingTeam = bowlingTeam;
        bowlingTeam = battingTeam == teamA ? teamB : teamA;

        secondInning = new InningDetails(battingTeam, bowlingTeam, matchType);
        secondInning.start(firstInning.getTotalRuns() + 1);
        if (secondInning.getTotalRuns() < firstInning.getTotalRuns()) {
            firstInning.battingTeam.isWinner = true;
        }

        System.out.println();
        System.out.println("INNING " + 2 + " -- total Run: " + battingTeam.getTotalRuns());
        System.out.println("---Batting ScoreCard : " + battingTeam.teamName + "---");
        battingTeam.printBattingScoreCard();

        System.out.println();
        System.out.println("---Bowling ScoreCard : " + bowlingTeam.teamName + "---");
        bowlingTeam.printBowlingScoreCard();

        System.out.println();
        if (teamA.isWinner) {
            System.out.println("---WINNER---" + teamA.teamName);
        } else if (teamB.isWinner) {
            System.out.println("---WINNER---" + teamB.teamName);
        } else {
            System.out.println("---MATCH DRAW---");
        }

    }

    private Team toss(Team teamA, Team teamB) {
        if (Math.random() < 0.5) {
            return teamA;
        } else {
            return teamB;
        }
    }
}
