package CricBuzz.ScoreUpdater;

import CricBuzz.Inning.BallDetails;
import CricBuzz.Inning.BallType;

public class BowlingScoreUpdater implements ScoreUpdaterObserver {

    @Override 
    public void update(BallDetails ballDetails) {
        if(ballDetails.ballNumber == 6 && ballDetails.ballType == BallType.NORMAL){
            ballDetails.bowler.bowlingScoreCard.totalOversCount += 1;
        }

        switch(ballDetails.runType){
            case ZERO:
                ballDetails.bowler.bowlingScoreCard.runsGiven += 0;
                break;
            case ONE:
                ballDetails.bowler.bowlingScoreCard.runsGiven += 1;
                break;
            case TWO:
                ballDetails.bowler.bowlingScoreCard.runsGiven += 2;
                break;
            case THREE:
                ballDetails.bowler.bowlingScoreCard.runsGiven += 3;
                break;
            case FOUR:
                ballDetails.bowler.bowlingScoreCard.runsGiven += 4;
                break;
            case SIX:
                ballDetails.bowler.bowlingScoreCard.runsGiven += 6;
                break;
        }

        if(ballDetails.wicket != null){
            ballDetails.bowler.bowlingScoreCard.wicketsTaken += 1;
        }

        if(ballDetails.ballType == BallType.WIDE){
            ballDetails.bowler.bowlingScoreCard.wideBallCount += 1;
            ballDetails.bowler.bowlingScoreCard.runsGiven += 1;
        }

        if(ballDetails.ballType == BallType.NO_BALL){
            ballDetails.bowler.bowlingScoreCard.noBallCount += 1;
            ballDetails.bowler.bowlingScoreCard.runsGiven += 1;
        }

        if (ballDetails.bowler.bowlingScoreCard.totalOversCount > 0) {
            ballDetails.bowler.bowlingScoreCard.economyRate =
                    (double) ballDetails.bowler.bowlingScoreCard.runsGiven
                            / ballDetails.bowler.bowlingScoreCard.totalOversCount;
        } else {
            ballDetails.bowler.bowlingScoreCard.economyRate = 0.0;
        }
    }
    
}