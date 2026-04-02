package CricBuzz.Inning;

import java.util.ArrayList;
import java.util.List;

import CricBuzz.ScoreUpdater.BattingScoreUpdater;
import CricBuzz.ScoreUpdater.BowlingScoreUpdater;
import CricBuzz.ScoreUpdater.ScoreUpdaterObserver;
import CricBuzz.Team.Team;
import CricBuzz.Team.Wicket;
import CricBuzz.Team.WicketType;
import CricBuzz.Team.Player.PlayerDetails;

public class BallDetails {
    public int ballNumber;
    public BallType ballType;
    public RunType runType;
    public PlayerDetails striker;
    public PlayerDetails bowler;
    public Wicket wicket;
    List<ScoreUpdaterObserver> scoreUpdaterObserverList = new ArrayList<>();

    public BallDetails(int ballNumber) {
        this.ballNumber = ballNumber;
        scoreUpdaterObserverList.add(new BowlingScoreUpdater());
        scoreUpdaterObserverList.add(new BattingScoreUpdater());
    }

    public void startBallDelivery(Team battingTeam, Team bowlingTeam, OverDetails over) {
        striker = battingTeam.getStriker();
        bowler = over.bowler;
        ballType = BallType.NORMAL;

        if (isWicketTaken()) {
            runType = RunType.ZERO;
            wicket = new Wicket(WicketType.BOWLED, bowler, over, this);
            battingTeam.setStriker(null);
        } else {
            runType = getRunType();
            if (runType == RunType.ONE || runType == RunType.THREE) {
                battingTeam.swapStrikers();
            }
        }

        notifyScoreUpdaters(this);
    }

    private void notifyScoreUpdaters(BallDetails ballDetails) {
        for(ScoreUpdaterObserver observer : scoreUpdaterObserverList) {
            observer.update(ballDetails);
        }
    }

    private RunType getRunType() {
        double randomValue = Math.random();
        if (randomValue < 0.20) {
            return RunType.ZERO;
        } else if (randomValue < 0.35) {
            return RunType.ONE;
        } else if (randomValue < 0.60) {
            return RunType.TWO;
        } else if (randomValue < 0.80) {
            return RunType.THREE;
        } else if (randomValue < 0.90) {
            return RunType.FOUR;
        } else {
            return RunType.SIX;
        }
    }

    private boolean isWicketTaken() {
        if (Math.random() < 0.05) { // Assuming a 5% chance of taking a wicket
            return true;
        }
        return false;
    }
}
