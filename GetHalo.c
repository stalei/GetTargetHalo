//#  © Shahram Talei @ 2020 The University of Alabama
//#you can redistribute it and/or modify
//#it under the terms of the GNU General Public License as published by
//#the Free Software Foundation; either version 3 of the License, or
//#(at your option) any later version.
//#You should have received a copy of the GNU General Public License
//#along with this program.  If not, see <http://www.gnu.org/licenses/>.
//# This code is distributed as is and there is no warranty or technical support
//# This code reads the halo and subhalo
//# this is a function test and I have to embed this code as a function
//#inside PtagPP like void f(*file, snap,*hid,*subhid)

#include <stdio.h>
#include <stdlib.h>


void ReadTargetHalo(char *, int, int *,int *);

int main()
{
char file[500];
int snap=100;
int *hid, *subhid=NULL;
hid=malloc(sizeof(int));
*hid=-1;
subhid=malloc(sizeof(int));
*subhid=-1;
//int *subhid;
sprintf(file,"/home/shahram/Desktop/Research/3_Tagging/GetTargetHalo/merger.bin");
printf("copied filename\n");
ReadTargetHalo(file,snap,hid,subhid);
printf("after read\n");
printf("Halo:%d,Subhalo:%d\n",*hid,*subhid);
free(hid);
free(subhid);
return 0;
}

void ReadTargetHalo(char *FileName, int snap, int *hid,int *subhid)
{
  FILE *f;
  int s,h,sub,status=-1;
  f=fopen(FileName,"rb");
  printf("opened the file\n");
  if(f!=NULL)
  {
    do
    {
    status=fread(&s,sizeof(s),1,f);
    printf("read:s=%d\n",s);
    fread(&h,sizeof(h),1,f);
    printf("read h=%d\n",h);
    fread(&sub,sizeof(sub),1,f);
    printf("read:sub=%d\n",sub);
    if(s==snap)
     {
      *hid=h;
      //printf("read:sub=%d\n",*subhid);
      *subhid=sub;
      return;
     }
     //else
     //{
      // *hid=-1;
       //*subhid=-1;
     //}
   }while(status==1);
  }

fclose(f);
}
