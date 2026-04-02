package CricBuzz.Team.Player;

import java.util.Deque;
import java.util.List;
import java.util.Map;

public class PlayerBowlingController {
    Deque<PlayerDetails> bowlersList;
    Map<PlayerDetails, Integer> bowlerOverCountMap;
    PlayerDetails currentBowler;

    public PlayerBowlingController(List<PlayerDetails> bowlers) {
        this.bowlersList = new java.util.LinkedList<>(bowlers);
        this.bowlerOverCountMap = new java.util.HashMap<>();
        for (PlayerDetails bowler : bowlers) {
            bowlerOverCountMap.put(bowler, 0);
        }
    }

    public void getNextBowler(int maxOverCountPerBowler) {
        PlayerDetails nextBowler = bowlersList.poll();
        currentBowler = nextBowler;
        bowlerOverCountMap.put(nextBowler, bowlerOverCountMap.get(nextBowler) + 1);
        if (bowlerOverCountMap.get(nextBowler) < maxOverCountPerBowler) {
            bowlersList.addLast(nextBowler);
        }
    }

    public PlayerDetails getCurrentBowler() {
        return currentBowler;
    }

}
