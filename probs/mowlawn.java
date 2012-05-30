/*
ID: gestapo1
PROG: mowlawn
LANG: JAVA
*/
import java.io.*;
import java.util.Scanner;


public class mowlawn {

    public static final int MAXN = 100005;

    public static void main( String[] args ) throws Exception {
        int i;
        int n , k;
        int[] a = new int[ MAXN ];        
        Scanner in = new Scanner( new BufferedReader( new FileReader( "test.in" ) ) );
        //DataOutputStream out = new DataOutputStream ( new FileOutputStream("mowlawn.out") );
        //FileWriter out = new FileWriter( new File( "mowlawn.out" ) );
        PrintWriter out = new PrintWriter( new OutputStreamWriter( new FileOutputStream( "mowlawn.out" ) , "Unicode" ));

        n = in.nextInt();
        k = in.nextInt();
        
        for( i = 1 ; i <= n ; ++ i )
            a[ i ] = in.nextInt();

        for( i = n ; i > 0 ; -- i )
            out.printf( "%d ",  a[ i ] );
        out.println();

        out.flush();
        out.close();
    }

}