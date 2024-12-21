import java.util.*;
public class Multi
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int i,n;
        System.out.println("Which number's myultiplication table do you want?");
        n=sc.nextInt();
        
        for(i=10;i>=1;i--)
        {
            System.out.print(n*i+" ");
        }
    }
}