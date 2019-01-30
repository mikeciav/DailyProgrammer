/**
*Challenge #374 [Easy] Additive Persistence
*Calculate the additive persistence of a number, defined as how many loops you have to do
*summing its digits until you get a single digit number. Take an integer N:
* -Add its digits
* -Repeat until the result has 1 digit
*The total number of iterations is the additive persistence of N.
*
*BONUS
*The really easy solution manipulates the input to convert the number to a string and iterate over it. 
*Try it without making the number a strong, decomposing it into digits while keeping it a number.
**/
import java.math.BigInteger;
public class AdditivePersistence
{
  public static void main(String[] args)
  {
    if(args.length != 1) return;
    String input = args[0];
    System.out.println("Input = " + input);
    try{
        new BigInteger(input);
    }
    catch(NumberFormatException e){
        System.err.println("Input is not an integer. Exiting");
        return;
    }
    int resultString = calculateAdditivePersistence(input, 0);
    int resultInt = calculateAdditivePersistence(new BigInteger(input), 0);
    System.out.println("Result from the function with String input: " + resultString);
    System.out.println("Result from the function with Int input: " + resultInt);
  }
  
  private static int calculateAdditivePersistence(String input){
    return calculateAdditivePersistence(input, 0);
  }
  
  private static int calculateAdditivePersistence(String input, int iterations){
    if(new BigInteger(input).compareTo(BigInteger.TEN) < 0) return iterations;
    BigInteger total = BigInteger.ZERO;
    String[] digits = input.split("");
    for(String digit : digits){
      total = total.add(new BigInteger(digit));
    }
    System.out.println("String total = " + total);
    return calculateAdditivePersistence(total.toString(), ++iterations);
  }
  
  //Bonus    
  private static int calculateAdditivePersistence(BigInteger input){
    return calculateAdditivePersistence(input, 0);
  }
  
  private static int calculateAdditivePersistence(BigInteger input, int iterations){
    if(input.compareTo(BigInteger.TEN) < 0) return iterations;
    BigInteger total = BigInteger.ZERO;
    BigInteger place = BigInteger.ONE;
    for(BigInteger inputCopy = new BigInteger(input.toString()); inputCopy.compareTo(BigInteger.ZERO)>0; inputCopy = inputCopy.divide(BigInteger.TEN)){
      total = total.add((input.divide(place)).mod(BigInteger.TEN));
      place = place.multiply(BigInteger.TEN);
    }
    System.out.println("int total = " + total);
    return calculateAdditivePersistence(total, ++iterations);
  }
}