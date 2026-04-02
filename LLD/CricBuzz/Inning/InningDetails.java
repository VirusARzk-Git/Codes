package CricBuzz.Inning;

import java.util.ArrayList;
import java.util.List;

import CricBuzz.MatchType;
import CricBuzz.Team.Team;

public class InningDetails {
    public Team battingTeam;
    Team bowlingTeam;
    MatchType matchType;
    List<OverDetails> overs;

    public InningDetails(Team battingTeam, Team bowlingTeam, MatchType matchType) {
        this.battingTeam = battingTeam;
        this.bowlingTeam = bowlingTeam;
        this.matchType = matchType;
        overs = new ArrayList<>();
    }

    public void start(int runsToWin) throws Exception {
        battingTeam.chooseNextBatsman();

        int noOfOvers = matchType.getOvers();
        for (int overNumber = 1; overNumber <= noOfOvers; overNumber++) {
            bowlingTeam.chooseNextBowler(matchType.maxOverCountBowlers());
            OverDetails over = new OverDetails(overNumber, bowlingTeam.getCurrentBowler());
            boolean won = over.startOver(battingTeam, bowlingTeam, runsToWin);
            overs.add(over);
            if (won) {
                break;
            }

            battingTeam.swapStrikers();
        }
    }

    public int getTotalRuns() {
        return battingTeam.getTotalRuns();
    }
}
