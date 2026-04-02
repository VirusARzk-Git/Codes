package CricBuzz;

public class T20Match implements MatchType {
    @Override
    public int getOvers() {
        return 20;
    }

    @Override
    public int maxOverCountBowlers() {
        return 5;
    }
    
}
