package game;
import java.util.ArrayList;
public class Board {
	// private  ArrayList<ArrayList<Character>> b;
	private char [][]b;
	private int length;
	private int width;

	public Board(int length , int width) {
		this.length = length;
		this.width = width;
		/*
		this.b = new ArrayList<ArrayList<Character>>(length);
		for (int i = 0; i < length; i ++) {
			this.b.add(new ArrayList<Character>(width));
			ArrayList temp = this.b.get(i);
			for (int j = 0; j < width; j ++) {
				temp.set(j , ' ');
			}
		}
		this.b.get(3).set(3 , 'X');
		*/
		this.b = new char[length][width];
		for (int i = 0; i < length; i ++) {
			for (int j = 0; j < width; j ++) {
				b[i][j] = ' ';
			}
		}
		this.b[3][3] = 'O';
		this.b[4][4] = 'O';
		this.b[3][4] = 'X';
		this.b[4][3] = 'X';
	}

	public char getCell(int i , int j) {
		//return this.b.get(i).get(j);
		return this.b[i][j];
	}

	public void setCell(int i , int j , char c) {
		//this.b.get(i).set(i , c);
		this.b[i][j] = c;
	}

	public int  getLength() {
		return this.length;
	}

	public int getWidth() {
		return this.width;
	}

	public boolean isNotFull() {
		for (int i = 0; i < this.length; i ++) {
			for (int j = 0; j < this.width; j ++) {
				if (this.b[i][j] == ' ') {
					return true;
				}
			}
		}
		return false;
}


	public static void main (String[] args) {
		Board b = new Board(8 ,8);
		System.out.println(b.getCell(3, 3));
	}
}