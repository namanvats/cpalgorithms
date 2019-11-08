using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
        }
        public static void BubbleSort(int[] arrayI)
        {
            int i, j, varAux;
            int N = arrayI.Length;

            for (j = N - 1; j > 0; j--)
            {
                for (i = 0; i < j; i++)
                {
                    if (arrayI[i] > arrayI[i + 1])
                    {
                        varAux = arrayI[i];
                        arrayI[i] = arrayI[i + 1];
                        arrayI[i + 1] = varAux;
                    }
                }
            }
        }
    }
}
