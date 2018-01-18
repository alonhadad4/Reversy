public class ConsoleDisplay extends BoardDisplayer {
	public ConsoleDisplay (Board boa) {
		super(boa);
	}

	public void displayBoard(Board boa) {
		int length = boa.getLength();
		char [] tempArr = new char [length];
		for (int i = 1; i <= length; i++) {
				tempArr[i - 1] = (char)(48 + i);
				}
			System.out.print(" | ");
			for (int i = 0; i < length; i++) {
				System.out.print(tempArr[i] + " | ");
			}
			for (int i = 0; i < length; i++) {
				System.out.print(" \n .................................. \n");
				System.out.print(tempArr[i]);
					for (int j = 0; j < length; j++) {
						System.out.print("| " + b.getCell(i , j) + " ");
					}
				System.out.print("|");
			}
			System.out.print(" \n..................................\n");
	}
	
}