#include <bits/stdc++.h>
using namespace std;
int main()
{
     float a[130][5], d[130];
     char str[125],str2[125];
     float sl = 0.0, sw = 0.0, pl = 0.0, pw = 0.0, sl1 = 0.0, sw1 = 0.0, pl1 = 0.0, pw1 = 0.0;
     int i = 0, j = 0, k = 0, c=0,key = 13, m = 0, l = 0, maxi = 0, setosa = 0, versicolor = 0, virginica = 0, it = 0;
     FILE *fp1, *fp2, *fp3;
     fp1 = freopen("data_training.txt", "r",stdin);
     while(i<120)
     {
          fscanf(fp1, " %f %f %f %f %s ", &sl, &sw, &pl, &pw, str);
          a[i][0] = sl;
          a[i][1] = sw;
          a[i][2] = pl;
          a[i][3] = pw;
          if(strcmp(str, "setosa") == 0)
          {
               a[i][4] = 0;
          }
          else if(strcmp(str, "versicolor") == 0)
          {
               a[i][4] = 1;
          }
          else if(strcmp(str, "virginica") == 0)
          {
               a[i][4] = 2;
          }
          i++;
     }
     /*for(i = 0; i < 120; i = i+1)
     {
         for(j=0;j<5;j++)
          cout << a[i][j]<<"    ";
          cout<<endl;
     }*/



     fp2 = freopen("test.txt","r", stdin);
      it = 0;
     while(it < 30)
     {
          fscanf(fp2, "%f %f %f %f %s", &sl1, &sw1, &pl1, &pw1, str2);
          //cout<<sl1<<"  "<<sw1<<"  "<<pl1<<"  "<<pw1<<"  "<<endl;
          it++;
          setosa = virginica = versicolor = 0;
          for (i = 0; i < 120; i++)
          {
               d[i] = sqrt((pow((a[i][0] - sl1), 2)) + (pow((a[i][1] - sw1),2)) + (pow((a[i][2] - pl1), 2)) + (pow((a[i][3] - pw1),2)));
               //cout << d[i] << endl;
          }
          //int sum=0;
         /* for (i=0; i<120; i++)
          {
              sum=sum+d[i];
          }*/

          //cout<< sum << endl;

          for (j = 0; j < 120; j++)
          {
               for(k = 0; k < 120-j-1; k++)
               {
                    if(d[k] > d[k+1])
                    {
                         swap(d[k+1], d[k]);
                         swap(a[k+1][0], a[k][0]);
                         swap(a[k+1][1], a[k][1]);
                         swap(a[k+1][2], a[k][2]);
                         swap(a[k+1][3], a[k][3]);
                         swap(a[k+1][4], a[k][4]);
                    }
               }
          }


       /* for(j=0;j<120;j++)
         {
                cout<<a[j][0]<<"  "<<a[j][1]<<"   "<<a[j][2]<<"   "<<a[j][3]<<"  "<<a[j][4]<<"   "<<d[j]<<endl;
        }*/
         for (m = 0; m <60; m++)
          {
               if(a[m][4] == 0)
                    setosa++;
               else if (a[m][4] == 1)
                    versicolor++;
               else if (a[m][4] == 2)
                    virginica++;
          }
          //cout << setosa << endl << versicolor << endl << verginica <<endl;
          if(setosa >= versicolor && setosa >= virginica)
          {
              cout<<"setosa"<<endl;
               if(strcmp(str2,"setosa")==0)
                    c++;
          }
          else if (versicolor >= setosa && versicolor >= virginica)
          {
               cout<<"versicolor"<<endl;
               if(strcmp(str2,"versicolor")==0)
                    c++;
          }
          else if(virginica >= setosa && virginica >= versicolor)
          {
               cout<<"virginica"<<endl;
                if(strcmp(str2,"virginica")==0){
                    c++;
                }
          }
          cout<<c<<endl;

    }
    float accuracy;
    accuracy = (c*100)/30;
    cout<<accuracy<<endl;
     //cout << setosa << endl << versicolor << endl << verginica <<endl;
     fclose(fp1);
     fclose(fp2);
     return 0;
}
//KNN.txt
//Displaying KNN.txt.
