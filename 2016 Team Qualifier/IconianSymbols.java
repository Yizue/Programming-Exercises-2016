
import java.util.Scanner;

public class IconianSymbols {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testNum = sc.nextInt();
        
        for (int i=0; i<testNum; i++) {
            String equation = sc.next();
            String num1 = "", num2 = "", sol = "", op = "";
            int result = -1;
            
            int j=1;
            boolean conditionA = false, conditionB = false;
            
            num1 += equation.substring(0, 1);
            
            while (!conditionA) {
                String test1 = equation.substring(j, j+1);
                if((!test1.equals("+")) && (!test1.equals("-")) && (!test1.equals("*"))) {
                    num1 += test1;
                    j++;
                }
                else {
                    conditionA = true;
                }  
            }
            
            op = equation.substring(j, j+1);
            j++;
            
            while (!conditionB) {
                String test2 = equation.substring(j, j+1);
                if(!test2.equals("=")) {
                    num2 += test2;
                    j++;
                }
                else {
                    conditionB = true;
                }  
            }
            j++; // "="
            
            sol += equation.substring(j, equation.length());
            
            for (int k=0; k<=9; k++) {
                int temp1 = Integer.parseInt(num1.replace('?',  Integer.toString(k).charAt(0)));
                int temp2 = Integer.parseInt(num2.replace('?', Integer.toString(k).charAt(0)));
                int temp3 = Integer.parseInt(sol.replace('?',  Integer.toString(k).charAt(0)));
                
                if(op.equals("+")) {
                   if(temp1 + temp2 == temp3) {
                       result = k;
                       break;
                   }      
                }
                else if(op.equals("*")) {
                    if(temp1 * temp2 == temp3) {
                       result = k;
                       break;
                   }      
                }
                else if(op.equals("-")) {
                    if(temp1 - temp2 == temp3) {
                       result = k;
                       break;
                   }      
                }
            }
            
            System.out.println(result);
        }
    }
    
}
