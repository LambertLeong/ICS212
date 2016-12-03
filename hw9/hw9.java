import java.util.Scanner;
import java.util.Formatter;

public class hw9 {
	
    static
    {
        System.loadLibrary("hw9");
    }

    private native int roundUp(int input);
    private native float convertFtoC(int input);

	public static void main(String[] args) 
	{
		int max, exit;
		String out;
        
		hw9 cfunc = new hw9();
		
		Scanner input = new Scanner( System.in ); 
		
		max =  exit = 0;
		
		System.out.println("\nPlease Enter an integer value greater than zero");
		
		while(exit < 1)
		{
			if ((!input.hasNextInt()))
			{
				System.out.println("Error!\nEnter an Integer!");
				input.next();
			}
			else
			{
				max = input.nextInt();
				if (max < 1)
				{
					System.out.println("Error!\nEnter a number GREATER than ZERO");
				}
				else
				{
					exit = 2;
					System.out.println("You've Entered "+max+"\n");
				}
			}
		}
		max = cfunc.roundUp(max);
        cfunc.printfunc(max);
	}
    void printfunc(int max)
	{
		int start;
		String out;
		start = 0;
		System.out.println("Tempurature in F\t\tTempurature in C");
		while(start<=max)
		{
            out = String.format("%.2f", convertFtoC(start));
			System.out.println("   \t"+start+"\t\t\t\t"+out);
			start +=5;
		}
	}

}
