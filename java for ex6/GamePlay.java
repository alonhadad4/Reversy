import java.util.List;
public class GamePlay {
	private GameRules rules;
	private Board b;
	private Player p1;
	private Player p2;
	private BoardDisplayer disp;

	public GamePlay(GameRules rul , Board  boa, Player playerOne , Player playerTwo) {
	// TODO Auto-generated constructor stub
	this.rules = rul;
	this.b = boa;
	this.p1 = playerOne;
	this.p2 = playerTwo;
	this.disp = new ConsoleDisplay(this.b);

	}

	public List getPossibleMoves(Player p) {
		return this.rules.possibleMoves(p , this.b);
	}

	/**
	 * runs the game until both players has no possible moves or the board's full.
	 */
	public void playGame() {
		this.disp.displayBoard(this.b);
		boolean possibleMovesForP1 = true;
		boolean possibleMovesForP2 = true;
		while (this.b.isNotFull() && (possibleMovesForP1 || possibleMovesForP2)) {
			possibleMovesForP1 = this.p1.playOneTurn(this);
			this.disp.displayBoard(this.b);
			possibleMovesForP2 = this.p2.playOneTurn(this);
			this.disp.displayBoard(this.b);
		}
		int countPlayerOne = 0;
		int countPlayerTwo = 0;
		char cOne = this.p1.getChar();
		char cTwo = this.p2.getChar();
		for (int i = 0; i < this.b.getLength(); i ++) {
			for (int j = 0; j < this.b.getWidth() ; j ++) {
				if (this.b.getCell(i , j) == cOne) {
					countPlayerOne ++;
				} else if (this.b.getCell(i , j) == cTwo) {
					countPlayerTwo ++;
				}
			}
		}
		if (countPlayerOne > countPlayerTwo) {
			System.out.println("Player one wins!");
		} else if (countPlayerTwo > countPlayerOne) {
			System.out.println("Player two wins!");
		} else {
			System.out.println("It's a tie!");
		}
	}


	public void move(Player p , int i , int j) {
		char c = p.getChar();
		this.rules.performMove(c , i , j , this.b);
	}

	public static void main (String[] args) {
		Board b = new Board(8 , 8);
		Player p1 = new HumanConsolePlayer('X');
	    Player p2  = new HumanConsolePlayer('O');
		GameRules rules = new BasicGameRules();
		GamePlay game = new GamePlay(rules , b , p1 , p2);
		game.playGame();
		}
}