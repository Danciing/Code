import static org.junit.Assert.assertEquals;
import org.junit.Test;


public class ExampleTests {

	////////////
	/** TODO
	 *	Jifeng: Change the path of "pathFile" to your local path.
	 */
	String pathFile = "C:\\Users\\YztHowe\\Desktop\\Code\\Code\\软测\\src\\test\\java\\Example.java";
	////////////
	
	String methodName1 = "reach1";
	String methodName2 = "reach2";
	String methodName3 = "reach3";
	
	/** TODO
	 * 	Jifeng: Write down the source code of your own MyDetector. 
	 */
	MyDetector myDetector = new MyDetector();
	
	/**
	 * 	Jifeng: You do not need to update the following-up code. 
	 */
	@Test
	public void testReach1()
	{
		assertEquals("(43 > 59 || 25 < 124) && (25 < 24)",  myDetector.getCondition   (pathFile, methodName1, "a"));
		assertEquals(false,                                 myDetector.getReachability(pathFile, methodName1, "a"));
		
		assertEquals("(43 > 59 || 25 < 124) && !(25 < 24)", myDetector.getCondition   (pathFile, methodName1, "b"));
		assertEquals(true,                                  myDetector.getReachability(pathFile, methodName1, "b"));
	}
	
	@Test
	public void testReach2()
	{
		assertEquals("(45 < 35 * 2) && (21 < 3 && 41 > 5)", myDetector.getCondition   (pathFile, methodName2, "a"));
		assertEquals(false,                                 myDetector.getReachability(pathFile, methodName2, "a"));
		
		assertEquals("(45 < 35 * 2) && !(21 < 3 && 41 > 5) && (14 > 1 || 4 < 9 * 2)", myDetector.getCondition   (pathFile, methodName2, "b"));
		assertEquals(true,                                                            myDetector.getReachability(pathFile, methodName2, "b"));
	}
	
	@Test
	public void testReach3()
	{
		assertEquals("(3 * 2 > 5) && (2 * 3 > 4) && (41 > 5 + 6 && 3 > 3 - 2)", myDetector.getCondition   (pathFile, methodName3, "a"));
		assertEquals(true,                                                      myDetector.getReachability(pathFile, methodName3, "a"));
		
		assertEquals("(3 * 2 > 5) && !(2 * 3 > 4)", myDetector.getCondition   (pathFile, methodName3, "b"));
		assertEquals(false,                         myDetector.getReachability(pathFile, methodName3, "b"));
	}
}
