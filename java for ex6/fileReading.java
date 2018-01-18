import java.io.*;
public static void main (String[] args) {
		
		BufferedReader bufferedReader = null;
		String [] definitions = {""};
		try {
			File file = new File("foo.txt");
			FileInputStream inputStream = new FileInputStream(file);
			bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
		} catch (FileNotFoundException e) {
			System.out.println("unable to find file");
			System.exit(1);
		} catch (Exception e) {
			System.out.println("buufered reader failed");
			System.exit(1);
		}
		
		String line;
		try {
			line = bufferedReader.readLine();
			definitions = line.split(",");
		} catch (IOException e) {
			System.out.println("coudln't read line");
		}
		int i = Integer.parseInt(definitions[2]);
		int j = Integer.parseInt(definitions[3]);
		System.out.println(i + " " +  j + " " + i + j);
		
		Board b = new Board(8 , 8);
		Player p1 = new HumanConsolePlayer('X');
	    Player p2  = new HumanConsolePlayer('O');
		GameRules rules = new BasicGameRules();
		GamePlay game = new GamePlay(rules , b , p1 , p2);
		game.playGame();
}