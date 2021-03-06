#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  Η συνάρτηση saveFile δέχεται το όνομα του αρχείου και ένα πίνακα
  και το σύνολο των συντεταγμένων. Ανοίγει το αρχείο και γράφει σε
  αυτό ανα σειρά όλο τον πίνακα.
*/
void saveFile(char* filename, float* cords[3],int n)
{
    FILE *fp;
    fp = fopen(filename,"w");
    if (!fp)
    {
        puts("Error opening file\n");
        return;
    }
    int i;
     for(i=0;i<n;i++)
     {
         int k;
         for(k=0;k<3;k++)
         {   if(k<2)
             {   if(cords[i][k]<10)
                 fprintf(fp,"%d%.6f ",0,cords[i][k]);
                 else
                 fprintf(fp,"%.6f ",cords[i][k]);
             }
             else
             {   if(cords[i][k]<10)
                 fprintf(fp,"%d%.6f\n",0,cords[i][k]);
                 else
                 fprintf(fp,"%.6f\n",cords[i][k]);
             }
         }
     }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    /*
      Έλεγχος ορισμάτων που δίνονται στο κάλεσμα
    */
    if (argc<1 || argc>3)
    {
      printf("Error");
      return 0;
    }
    /* Το πρώτο όρισμα (filename) αφορά το όνομα του αρχείου
      και το δεύτερο τον αριθμό των συντεταγμένων
    */
    char* filename=argv[1];
    int coordinate_index=atoi(argv[2]);
    int utime;
    long int ltime;
    int i,j;
    /*
      Δημιουργία δυναμικού πίνακα για αποθήκευση των τριών συντεταγμένων ανα σειρά.
    */
    float **cords;
    cords=calloc(coordinate_index,sizeof(float*));
    for(j=0;j<coordinate_index;j++)
    {
      cords[j]=calloc(3,sizeof(float));
    }
    /*
      Δωσμένος κώδικας από τα pdfs με αλλαγή του coordinate_index,
      το οποίο δίνεται σαν όρισμα.
    */
    ltime = time(NULL);
    utime = (unsigned int) ltime/2;
    srand(utime);
    for(i=0;i<coordinate_index;i++)
    {
      cords[i][0]=(float)34*rand()/(RAND_MAX-1);
      cords[i][1]=(float)34*rand()/(RAND_MAX-1);
      cords[i][2]=(float)34*rand()/(RAND_MAX-1);
    }
    saveFile(filename,cords,coordinate_index);
    for (j=0;j<coordinate_index;j++)
    {
      free(cords[j]);
    }
    free(cords);
}
