package CricBuzz.Inning;

import java.util.ArrayList;
import java.util.List;

import CricBuzz.Team.Team;
import CricBuzz.Team.Player.PlayerDetails;

public class OverDetails {
    int overNumber;
    List<BallDetails> balls;
    int extraBalls;
    PlayerDetails bowler;

    OverDetails(int overNumber, PlayerDetails bowler) {
        this.overNumber = overNumber;
        balls = new ArrayList<>();
        this.bowler = bowler;
    }

    public boolean startOver(Team battingTeam, Team bowlingTeam, int runsToWin) throws Exception {
        int ballCount = 1;
        while (ballCount <= 6) {
            BallDetails ball = new BallDetails(ballCount);
            ball.startBallDelivery(battingTeam, bowlingTeam, this);

            if (ball.ballType == BallType.NORMAL) {
                balls.add(ball);
                ballCount++;
                if (ball.wicket != null) {
                    try {
                        battingTeam.chooseNextBatsman();
                    } catch (Exception e) {
                        // Innings ends when there is no batsman left.
                        return true;
                    }
                }

                if (runsToWin != -1 && battingTeam.getTotalRuns() >= runsToWin) {
                    battingTeam.isWinner = true;
                    return true;
                }
            } else {
                extraBalls++;
            }
        }
        return false;
    }
}
