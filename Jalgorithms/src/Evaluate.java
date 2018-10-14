//Dijkstra的双栈算术表达式求值算法

import java.util.Stack;

public class Evaluate {
    public static Double evaluate(String  exp){
        String trimedExp = exp.trim();
        String[] tokens=trimedExp.split(" ");
        Stack<String> ops = new Stack<String>();
        Stack<Double> vals = new Stack<Double>();
        for(String token : tokens ){
            if(token.equals(" ") || token.equals("(")) continue;
            else if (token.equals("+")) ops.push("+");
            else if (token.equals("-")) ops.push("-");
            else if (token.equals("*")) ops.push("*");
            else if (token.equals("/")) ops.push("/");
            else if (token.equals("sqrt")) ops.push("sqrt");
            else if (token.equals(")")){
                String op = ops.pop();
                Double val = vals.pop();
                if(op.equals("+")) vals.push(vals.pop() + val);
                else if(op.equals("-")) vals.push(vals.pop() - val);
                else if(op.equals("*")) vals.push(vals.pop()* val);
                else if(op.equals("/")) vals.push(vals.pop()/val);
                else if(op.equals("sqrt")) vals.push(Math.sqrt(val));
            }
            else vals.push(Double.parseDouble(token));
        }
        return vals.pop();
    }


    public static void main(String[] args) {
        Double result1 =evaluate("( 1 + ( 2 * 3 ) )");
        System.out.println(result1);

        Double result2 =evaluate("( ( 1 + ( 2 * 3 ) ) + ( sqrt ( 4.0 ) / 2.0 ) )");
        System.out.println(result2);
    }
}
