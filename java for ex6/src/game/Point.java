package game;
public class Point {
	private int x;
	private int y;

	/**
	 * initializes members of point
	 * @param firstNum , x coordinate of move
	 * @param secondNum , y coordinate of move
	 */
	public Point(int firstNum , int secondNum) {
		this.x = firstNum;
		this.y = secondNum;
	}

	/**
	 * sets x coordinate to num.
	 * @param num
	 */
	public void setX(int num) {
		this.x = num;
	}

	/**
	 * sets y coordinate to num.
	 * @param num
	 */
	public void setY(int num) {
		this.y = num;
	}

	/**
	 * @return x coordinate.
	 */
	public int getX() {
		return this.x;
	}

	/**
	 * @return y coordinate.
	 */
	public int getY() {
		return this.y;
	}
}