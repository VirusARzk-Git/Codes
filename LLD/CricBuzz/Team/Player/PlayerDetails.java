package CricBuzz.Team.Player;

import java.util.Locale;

import CricBuzz.Team.Player.Score.BattingScoreCard;
import CricBuzz.Team.Player.Score.BowlingScoreCard;

public class PlayerDetails {
    public Person person;
    public PlayerType playerType;
    public BattingScoreCard battingScoreCard;
    public BowlingScoreCard bowlingScoreCard;

    public PlayerDetails(Person person, PlayerType playerType) {
        this.person = person;
        this.playerType = playerType;
        this.battingScoreCard = new BattingScoreCard(); 
        this.bowlingScoreCard = new BowlingScoreCard();
    }

    public void printBattingScoreCard() {
        String wicket = battingScoreCard.wicketDetails != null
                ? battingScoreCard.wicketDetails.wicketType.toString()
                : "Not Out";
        System.out.printf(
                Locale.ROOT,
                "%-14s %5d %5d %4d %4d %8.2f %-12s%n",
                person.name,
                battingScoreCard.totalRunsScored,
                battingScoreCard.totalBallsPlayed,
                battingScoreCard.foursCount,
                battingScoreCard.sixesCount,
                battingScoreCard.runRate,
                wicket);
    }

    public void printBowlingScoreCard() {
        System.out.printf(
                Locale.ROOT,
                "%-14s %5d %5d %5d %4d %4d %8.2f%n",
                person.name,
                bowlingScoreCard.totalOversCount,
                bowlingScoreCard.runsGiven,
                bowlingScoreCard.wicketsTaken,
                bowlingScoreCard.noBallCount,
                bowlingScoreCard.wideBallCount,
                bowlingScoreCard.economyRate);
    }

}
