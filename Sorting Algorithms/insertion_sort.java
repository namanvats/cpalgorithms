import java.io.*;
class Insertion
{
  public static void main()throws IOException
  {
    BufferedReader br=new BufferedReader (new InputStreamReader(System.in));
    int n,l,key,i,j;
    System.out.println("Enter the size of the array");
    n=Integer.parseInt(br.readLine());
    int a[]=new int[n];
    System.out.println("Enter the array elements");
    for(i=0;i<n;i++)
        a[i]=Integer.parseInt(br.readLine());
    System.out.println("ORGINAL ARRAY : ");
    for(i=0;i<n;i++)
        System.out.println(a[i]);
        
    //Sorting algorithm
    for(i=1;i<n;i++)
    {
       key = a[i]; 
       j = i - 1; 
        /* Move elements of arr[0..i-1], that are 
           greater than key, to one position ahead 
               of their current position */
        while (j >= 0 && a[j] > key)
        { 
          a[j + 1] = a[j]; 
          j = j - 1; 
         } 
         a[j+1]=key;
         
      }
      //Displaying the array
      System.out.println("SORTED ARRAY : ");
      for(i=0;i<n;i++)
        System.out.println(a[i]);
   }
}
