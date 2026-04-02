package CricBuzz.Team.Player;

import java.util.LinkedList;
import java.util.Queue;

public class PlayerBattingController {

    Queue<PlayerDetails> yetToBat;
    PlayerDetails striker;
    PlayerDetails nonStriker;

    public PlayerBattingController(Queue<PlayerDetails> playing11) {
        this.yetToBat = new LinkedList<>(playing11);
    }

    public void getNextBatsman() throws Exception {
        if (yetToBat.isEmpty()) {
            throw new Exception();
        }

        if (striker == null) {
            striker = yetToBat.poll();
        }

        if (nonStriker == null) {
            nonStriker = yetToBat.poll();
        }
    }

    public PlayerDetails getStriker() {
        return striker;
    }

    public void setStriker(PlayerDetails player) {
        this.striker = player;
    }

    public PlayerDetails getNonStriker() {
        return nonStriker;
    }

    public void setNonStriker(PlayerDetails player) {
        this.nonStriker = player;
    }

}
