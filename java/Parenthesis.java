import java.util.HashMap;
import java.util.Stack;

public class Parenthesis {
	private static final String opener = "([{";
	private static final String closer = ")]}";
	
	@SuppressWarnings("serial")
	private static final HashMap<Character,Character> pair = new HashMap<Character,Character>(){
		{
			put('[',']');
			put('(',')');
			put('{','}');
		}
	};

	public boolean validate(String str){
		Stack<Character> stack = new Stack<>();

		for(int i=0;i<str.length();i++){
			char ch = str.charAt(i);
			if(opener.indexOf(ch)!=-1)
				stack.push(ch);
			
			if(closer.indexOf(ch)!=-1){
				if(stack.isEmpty())
					return false;
				else if(pair.get(stack.pop()) != ch)
					return false;
			}
		}

		if(!stack.isEmpty())
			return false;

		return true;
	}
	
	public static void main(String[] args){
		Parenthesis obj = new Parenthesis();
		System.out.println("This is a (great) {book} " + obj.validate("This is a (great) {book}"));
		System.out.println("([)] " + obj.validate("([)]"));
		System.out.println("([) " + obj.validate("([)]"));
		System.out.println("()] " + obj.validate("([)]"));
		System.out.println("" + obj.validate(""));
		System.out.println("][ " + obj.validate("]["));
		System.out.println("({{{{[()]}}}})" + obj.validate("({{{{[()]}}}})"));
	}
}
