package CricBuzz;

public class OneDayMatch implements MatchType {
    @Override
    public int getOvers() {
        return 50;
    }

    @Override
    public int maxOverCountBowlers() {
        return 10;
    }

}
