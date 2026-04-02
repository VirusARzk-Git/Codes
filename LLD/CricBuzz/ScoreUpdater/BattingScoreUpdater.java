package CricBuzz.ScoreUpdater;

import CricBuzz.Inning.BallDetails;

public class BattingScoreUpdater implements ScoreUpdaterObserver {

    @Override
    public void update(BallDetails ballDetails) {
        int run = 0;

        switch(ballDetails.runType){
            case ZERO:
                run = 0;
                break;
            case ONE:
                run = 1;
                break;
            case TWO:
                run = 2;
                break;
            case THREE:
                run = 3;
                break;
            case FOUR:
                run = 4;
                ballDetails.striker.battingScoreCard.foursCount += 1;
                break;
            case SIX:
                run = 6;
                ballDetails.striker.battingScoreCard.sixesCount += 1;
                break;
        }
        ballDetails.striker.battingScoreCard.totalRunsScored += run;
        ballDetails.striker.battingScoreCard.totalBallsPlayed += 1;
        if (ballDetails.striker.battingScoreCard.totalBallsPlayed > 0) {
            ballDetails.striker.battingScoreCard.runRate =
                (ballDetails.striker.battingScoreCard.totalRunsScored * 6.0)
                            / ballDetails.striker.battingScoreCard.totalBallsPlayed;
        }

        if(ballDetails.wicket != null){
            ballDetails.striker.battingScoreCard.wicketDetails = ballDetails.wicket;
        }
    }
    
}
