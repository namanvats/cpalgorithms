	#include <iostream>
#include "seqLinearList.hpp"
 
template<class Item>
class Sort{
  private:
  public:
    void insertionSort(LinearList<Item>& A)
    {
      int l=A.length();
      Item t,y;
      for(int j=2;j<=l;j++)
      {
          Item key=A.operator[](j);
          int i=j-1;
          while(i>0 && A.operator[](i)>key)
          {
           t=A.deleteElement(i);
           A.insert(i+1,t);
           i=i-1;
          }
          t=A.deleteElement((i+1));
          A.insert(i+1,key);
      }
    }

    void rankSort(LinearList<Item>& A, int low, int high)
    {
      int n=A.length();
      Item d=1;
      int x;
      LinearList<int> R(n);
      LinearList<int> P(n);
      for (int j = 2; j <= n; ++j)
      { 
                for (int i = 1; i<=j-1; ++i)
                {
                  if(A.operator[](i)<=A.operator[](j))
                      R[j]=R[j]+1;
                  else
                      R[i]=R[i]+1;   
               }
        }
         

        for (int k = 1; k <= n; ++k)
        {    
          int f;
          f=P.find(R.operator[](k),A.operator[](k));
               
        }
        
        for (int k = 1; k <= n; ++k)
        {   
          int f;
          f=A.find(k,P.operator[](k));
        } 
    }

    void bubbleSort(LinearList<Item>& A, int low, int high)
    {
      int l=A.length();
      int j=l;
      while(j>=2)
      {
        for(int i = 1; i <=j-1; ++i)
        { 
          if(A.operator[](i+1)<A.operator[](i))
          {
            Item t=A.deleteElement(i);
            A.insert(i+1,t);
          }
        }
        j=j-1;
      }
    }
    

    

    void merge(LinearList<Item>& A,int low,int mid,int high)
    {  
       
      int n1=mid-low+1;
      int n2=high-mid;
      LinearList<Item> A1(n1);
      LinearList<Item> A2(n2);
      int j=low;
      for (int i = 1; i <=n1; ++i)
      {
        A1.find(i,A.operator[](j));
        j++;
      }
      int k=mid+1;
      for (int i = 1; i <=n2; ++i)
      {
        A2.find(i,A.operator[](k));
        k++;
      }
      int b=1,c=1;
      for (int m = low; m<=high; m++)
          { 
            if(A1.operator[](b)<=A2.operator[](c) && b<=n1 && c<=n2)
                {
                    A.find(m,A1.operator[](b));
                    b++; 
                }
                else if(b<=n1 && c<=n2 && A1.operator[](b)>A2.operator[](c))
                {
                    A.find(m,A2.operator[](c));
                    c++; 
                }
                else if(b>n1)
                {
                  A.find(m,A2.operator[](c));
                  c++; 
                }
                else if(c>n2)
                {
                  A.find(m,A1.operator[](b));
                  b++; 
                }
          }
          
     
    }
        
        void mergeSort(LinearList<Item>& A, int low, int high)
        {
          if(low<high)
          {
            int mid;
            mid=(low+high)/2;
            mergeSort(A,low,mid);
            mergeSort(A,mid+1,high);
            merge(A,low,mid,high);
          }

              
        }
        
        void selectionSort(LinearList<Item>& A, int low, int high)
        {
        int n=A.length();
        Item temp;
            int sorted=0,pos;
            int j=n;
            while(j>1 && sorted==0)
            {
              pos=1;
              sorted=1;// sorted=true
            for(int i=2;i<=j;i++)
            { 
              if(A.operator[](pos)<=A.operator[](i))
                pos=i;
              else
                sorted=0;
            }
            Item temp2=A.operator[](j);
            temp=A.deleteElement(pos);
            A.insert(pos,temp2);
            Item temp1=A.deleteElement(j);
            A.insert(j,temp);
            j=j-1;
            } 
        }        
        void heapify(LinearList<Item>& A,int h,int n)
        {    
          int left,right,smallest;
          left=2*h;
          right=2*h+1;
          if(left<=n && A.operator[](left)>A.operator[](h))
               smallest=left;
          else
              smallest=h;
          if(right<=n && A.operator[](right)>A.operator[](smallest))
              smallest=right;
          if(smallest!=h)
          {
            Item temp1= A.operator[](h);
            Item temp=A.deleteElement(smallest);
            A.insert(smallest,temp1);
            Item temp2=A.deleteElement(h);
            A.insert(h,temp);
            heapify(A,smallest,n);
          }
        }
        void buildHeap(LinearList<Item>& A,int n)
        {   
          for (int i = n/2; i >0; i--)
          {
            heapify(A,i,n);
          }
        }
        void heapsort(LinearList<Item>& A)
        {    
             int n;
             n =A.length();
             buildHeap(A,n);
             for (int i = n; i >1; --i)
             {    
              Item temp1= A.operator[](1);
              Item temp=A.deleteElement(i);
              A.insert(i,temp1);
              Item temp2=A.deleteElement(1);
              A.insert(1,temp);
              n=n-1;
              heapify(A,1,n);
             }
        } 
      /*  int partition(LinearList<Item>& A, int low, int high)
        {
          Item pivot=A.operator[](high);
          int i=low-1,j=high+1;
          while(1)
          {
            do
              j=j-1;
            while(A.operator[](j)>pivot);
            do
              i=i-1;
            while(A.operator[](i)<pivot); 
            if(j>i)
              {
                Item temp=A.deleteElement(i);
                A.insert(i+1,temp);
              }
            else if(j==i)
              return j-1;
            else
              return j;
          }
        }
        void quickSort(LinearList<Item>& A, int low, int high)
        {   
          int z;
          cout<<z;
          if(low<high)
          {
               z=partition(A,low,high);
               quickSort(A,low,z);
               quickSort(A,z+1,high);
          }

        }   */  
        

    void quickSort(LinearList<Item>& A, int low, int high)
    {
        if(low<high)
        {
            int pivot = partition( A, low, high);
            cout<<"pivot"<<pivot<<endl;
            quickSort( A, low, pivot-1);
            quickSort( A, pivot, high);
            cout<<"end"<<endl;
        }
    }
    int partition(LinearList<Item>& A, int low, int high)
    {
        int i = low;
        for(int j=low; j<high; j++)
        {
            if(A.operator[](j)<=A.operator[](high))
            {
                //swap(A[i],A[j]);
                //cout<<A.operator[](j)<<"2  "<<A.operator[](high)<<endl;
                Item temp1=A.deleteElement(j);
                Item temp2=A.deleteElement(i);
                A.insert(j,temp2);
                A.insert(i,temp1);
                ++i;
            }
        }
        //swap(A[i],A[high]);

        //cout<<A.operator[](i)<<" 1 "<<A.operator[](high)<<endl;

        Item temp1=A.deleteElement(i);
        Item temp2=A.deleteElement(high);
        A.insert(i,temp2);
        A.insert(high,temp1);
        return(i);
    }

};
 
