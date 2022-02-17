#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<math.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

void mainmenu();
void login(long);

int count;
long pos;

class uv_bank
 { private:

   char mobile_no[10];
   long acc_no;
   char gender;
   int age;
   int mm,dd,yyyy;
   char aadhar_no[12];
   char cus_name[34];
   char password[10];
   char address[80];
   long current_amt;
   long passbook[100][2];
   int trans;
   char loan_type;
   long principle;
   long interest;
   double rate;
   long EMI;
   long loan_amt;
   int no_of_EMI;
   double time;

   public:

   void change_pass();
   void new_acc();
   void update_acc();
   void close_acc();
   void transfer();
   void deposit();
   void withdraw();
   void req_loan();
   void loan_details();
   void refresh_loan();
   void refresh_passbook();
   void showinfo();
   void getdata();
   void passbook_det();
   int check(long,char[]);
   long get_acc_no()
    { return acc_no; }
   char* get_password()
    { return password; }
   char* get_cusname()
    { return cus_name;}
   long get_balance()
    { return current_amt;}

 }uv,uvn,uvr;

 void main()
  {clrscr();
   long p;
      fstream fin("uvbank.dat",ios::out|ios::in|ios::binary);
      if(!fin)
      {
       cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
       cout<<"\tPlease try again later";
       delay(4000);
       exit(1);
      }
      fin.seekg(0,ios::end);
      p=fin.tellg();
      count=(p/sizeof(uv));
      fin.close();

     delay(3000);
     cout<<"\n\n\n\t\t\t    * * * U.V. BANK * * *";
     delay(1000);
     cout<<"\n\n\t\t\t     * A Name Of Trust *";
     delay(800);
     cout<<"\n\n\t\t_______________________________________________";
     delay(1000);
     cout<<"\n\n\t\t              A";
     delay(500);
     cout<<"   PROJECT";
     delay(500);
     cout<<"    BY";
     delay(2000);
     cout<<"\n\n\n\t\t\t\t Y U V R A J";
     delay(500);
     cout<<"\n\n\t\t\t    C H A K R A V E R T Y";
     delay(1000);
     cout<<"\n\n\t\t_______________________________________________";
     delay(800);
     cout<<"\n\n\t\t\t        CLASS  XII B";
     cout<<"\n\t\t\t      DON BOSCO SCHOOL ,";
     cout<<"\n\t\t\t          ALAKNANDA";
     delay(4000);
     clrscr();

     char v;
     char pp[8];
     cout<<"\n\n\n\n\t\t\t\t* * * UV BANK * * *";
     cout<<"\n\n\n\n\t1. Private Access\n\n\t2. Customer Access\n\n\n\t";
     cout<<"Press Any Other Key To Exit\n\n\n\t";
     v=getch();
     if(v=='1')
       {
	delay(1000);
	clrscr();
	char ll[8];
	int pass=1;
	{ll[0]='7';ll[1]='4';ll[2]='2';ll[3]='1';ll[4]='8';ll[5]='4';
	 ll[6]='9';ll[7]='1';}
	cout<<"\n\n\n\n\tEnter Password\n\n\t";
	for(int i=0;i<8;i++)
	    {pp[i]=getch();
	     cout<<"* ";
	     if(pp[i]!=ll[i])
	      {pass=0;}
	     }
	 delay(1500);
	 if(pass==1)
	  {
	   clrscr();
	   cout<<"\n\n\n\n\t\tWELCOME  YUVRAJ  !!!\n\n";
	   delay(1500);
	   cout<<"\n\n\t\t1. View Details Of All Your Customers\n\t";
	   cout<<"\t2. View Details Of A Particular Customer\n\t";
	   cout<<"\t3. Login In As A Customer\n\t";
	   cout<<"\t4. Go To Customer Access\n\t";
	   cout<<"\n\n\tPress Any Other Key to Exit\n\n";
	   cout<<"\n\n\tTotal Number Of Accounts :  "<<count;
	   cout<<"\n\n\n\tSize Of 1 Record In Bytes : "<<sizeof(uv);

	   char g;
	   g=getch();
	   if(g=='1')
	   {if(count==0)
	    {clrscr();
	     cout<<"\n\n\n\tNo Accounts Exist Yet";
	     cout<<"\n\n\n\tPress Any Key To Start Customer Access";
	     getch();
	     delay(1000);
	     mainmenu();}
	     fstream fin("uvbank.dat",ios::in|ios::out|ios::binary);
	     char p;
	     for(i=0;i<count;i++)
	     {clrscr();
	      cout<<"\n\n\n\tCustomer No. : "<<i+1<<"\n\n";
	      long u=fin.tellg();
	      fin.read((char*)&uv, sizeof(uv));
	      delay(1500);
	      uv.showinfo();
	      delay(2000);
	      cout<<"\n\n\tPress 'L' To Log In As Customer : "<<i+1;
	      cout<<"\n\n\tPress 'M' To Start Customer Access";
	      if((i+1)!=count)
	       {cout<<"\n\n\tPress Any Other Key To See Next Record";}

	      p=getch();
	       if(p=='l'||p=='L')
		{delay(1000);
		 pos=u;
		 login(pos);}
	       else if(p=='m'||p=='M')
		{delay(2000);
		 mainmenu();}
	       else {}
	      }}
	     else if(g=='2')
	      {if(count==0)
	       {clrscr();
		cout<<"\n\n\n\tNo Accounts Exist Yet";
		cout<<"\n\n\n\tPress Any Key To Start Customer Access";
		getch();
		delay(1000);
		mainmenu();}

	       fstream fin("uvbank.dat",ios::in|ios::out|ios::binary);
	       char p;
	       int a;
	       clrscr();
	       kl:
	       cout<<"\n\n\n\tEnter Customer No. ";
	       cin>>a;
	       if((a>count)||(a<=0))
		{cout<<"\n\n\n\tAccount Does Not Exist";
		 goto kl;}
	       cout<<"\n\n\n\tCustomer No. : "<<a<<"\n\n";
	       long u=(a-1)*sizeof(uv);
	       fin.seekg(u);
	       fin.read((char*)&uv, sizeof(uv));
	       delay(1500);
	       uv.showinfo();
	       fin.close();
	       delay(3000);
	       cout<<"\n\n\n\tPress 'L' To Login As Customer  "<<a;
	       cout<<"\n\n\tPress Any Other Key To Start Customer Access";
	       p=getch();
	       if(p=='l'||p=='L')
		{delay(1000);
		 pos=u;
		 login(pos);}
		delay(1000);
		mainmenu();
	       }
	     else if(g=='3')
	     {if(count==0)
	       {clrscr();
		cout<<"\n\n\n\tNo Accounts Exist Yet";
		cout<<"\n\n\n\tPress Any Key To Start Customer Access";
		getch();
		delay(1000);
		mainmenu();}
	       int a;
	       clrscr();
	       kp:
	       cout<<"\n\n\n\tEnter Customer No. ";
	       cin>>a;
	       if((a>count)||(a<=0))
		{cout<<"\n\n\n\tAccount Does Not Exist";
		 goto kp;}
	       long u=(a-1)*sizeof(uv);
	       pos=u;
	       cout<<"\n\n\n\tLogging In As Customer No. "<<a;
	       delay(1500);
	       login(pos);
	       }
	     else if(g=='4')
	     {delay(1000);
	      mainmenu();}
	     else
	     {delay(1000);
	      exit(0);}

	    delay(2500);
	    cout<<"\n\n\n\tPress Any Key To Go to Customer Access\n\n\t";
	    getch();
	    delay(3000);
	    mainmenu();}
	 else
	  {clrscr();
	   cout<<"\n\n\n\tIncorrect  Password !!!\n\n";
	   sound(8000);
	   delay(3000);
	   nosound();
	   char t;
	   cout<<"\n\n\nPress ' T ' To Go To Customer Access\n\n\t";
	   cout<<"Press Any Other Key to Exit\n\n\t";
	   t=getch();
	     if(t=='T'||t=='t')
	     mainmenu();
	     else
	     {delay(2000);
	      exit(0);}}
 }

      else if(v=='2')
      {delay(1000);;
       mainmenu();}
      else
      {delay(1500);
       exit(0);}

clrscr();
mainmenu();
getch();

}

void uv_bank::new_acc()
    {
     ofstream fout1("uvbank.dat",ios::out|ios::binary|ios::app);

     if(!fout1)
     {
      cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
      cout<<"\n\tPlease try again later";
      delay(4000);
      exit(1);
     }

     uv.getdata();
     long f;
     fout1.write((char *)&uv, sizeof(uv));
     f=fout1.tellp();
     clrscr();
     delay(1000);
     cout<<"\n\n\n\n\tAccount Created !!!\n";
     count++;
     fout1.close();
     delay(1500);
     cout<<"\n\n\n\tPress 'L' To Login Into Your New Account";
     cout<<"\n\n\n\tPress Any Other Key To Go To Main Menu";
     char y=getch();
     delay(1000);
     if(y=='L'||y=='l')
     {pos=f-sizeof(uv);
      login(pos);}
     else
     mainmenu();
    }

void uv_bank::getdata()
    {
     clrscr();
     int i;
     trans=0;
     cout<<"\n\n\n\tEnter Customer Details:\n\n";
     delay(1500);
     cout<<"\n\tEnter Name: ";
     gets(cus_name);
     cout<<"\n\tEnter 10 Digit Mobile No.: ";
     for(i=0;i<10;i++)
     {mobile_no[i]=getche();}
     cout<<"\n\n\tEnter Gender(M/F): ";
     op:
     gender=getch();
     gender=toupper(gender);
     putchar(gender);
      if((gender!='M')&&(gender!='F'))
       {
	cout<<"\n\n\tInvalid Entry\n\nPlease Enter Again : ";
	goto op;
       }
     cout<<"\n\n\tEnter AGE (Only Ages between 4 & 100 Eligible) : ";
     pl:
     cin>>age;
     if((age>100)||(age<4))
      {cout<<"\n\n\tInvalid Age\n\tPlease Enter Again : ";
       goto pl;}
     cout<<"\n\tEnter Date of Birth:";
     cout<<"\n\t    Date(DD):   ";
     cin>>dd;
     cout<<"\t    Month(MM):  ";
     cin>>mm;
     cout<<"\t    Year(YYYY): ";
     cin>>yyyy;
     cout<<"\n\tEnter Aadhar Card No.: ";
     an:
     for(i=0;i<12;i++)
     aadhar_no[i]=getche();
     for(i=0;i<12;i++)
     {if(isdigit(aadhar_no[i])==0)
      {
       cout<<"\n\tInvalid Aadhar Card No.!\n\tPlease Enter Again: ";
       goto an;
      }}
     cout<<"\n\n\tEnter Address \n\t ";
     gets(address);
     cout<<"\n\tEnter Opening Balance (min 5000, max 10,00,000): ";
     d:
     cin>>current_amt;
     if((current_amt>1000000)||(current_amt<5000))
     {cout<<"\n\n\tInvalid Entry\n\n\tPlease Enter Again : ";
      goto d;}
     if(current_amt<5000)
     {
      cout<<"\n\tInsufficient Opening Balance !!!\n\tPlease Deposit atleast Rs. 5000! : ";
      goto d;
     }
     passbook[trans][0]=current_amt;
     passbook[trans][1]=current_amt;
     trans++;
     cout<<"\n\tEnter 10 Character Password\n\n\t(Password can have Letters & Digits ONLY ) :\n\n\t";
     jk:
     for(i=0;i<10;i++)
      {password[i]=getche();
       if((isdigit(password[i])==0)&&(isalpha(password[i])==0))
	{cout<<"\n\n\n\tInvalid Character\n\n\tPlease Enter Again : ";
	 goto jk;}
      }
      delay(500);
      cout<<"\n\n\tPress 'R' To Re-Enter Password\n\n\tPress Any Other Key To Confirm Password";
      char ps=getch();
       if(ps=='r'||ps=='R')
	{cout<<"\n\n\tRe-Enter Password : ";
	 goto jk;}
       cout<<"\n\n\tYour Password is :  ";
       for(i=0;i<10;i++)
       putchar(password[i]);
	cout<<"\n\n\n\tPlease Carefully Note Your Password\n\t& Then Press Any Key To Continue";
	getch();

      loan_type='N';

      h:
      randomize();
      delay(1000);
      randomize();
      acc_no=random(100000000)+1100000000;

      ifstream fin2("uvbank.dat",ios::in|ios::binary);

      if(!fin2)
      {
       cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
       cout<<"\tPlease try again later";
       delay(4000);
       exit(1);
      }
      for(i=0;i<count;i++)
      {
       fin2.read((char *)&uvr, sizeof(uvr));
       if(uvr.acc_no==acc_no)
       {
	randomize();
	goto h;}
       }
      fin2.close();
      cout<<"\n\n\tYour Account No. is :  "<<acc_no;
      cout<<"\n\n\n\tPlease Carefully Note Your Account No.\n\t& Then Press Any Key To Continue";
      getch();
}

    void uv_bank::close_acc()
      {
       clrscr();
       char l;
       int flag=0;

       ofstream fout2("temp.dat",ios::out|ios::binary);

	   if(!fout2)
	   {
	    cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
	    cout<<"\tPlease try again later";
	    delay(4000);
	    exit(1);
	    }

	   fstream fin3("uvbank.dat",ios::out|ios::in|ios::binary);

	   if(!fin3)
	  {
	   cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
	   cout<<"\tPlease try again later";
	   delay(4000);
	   exit(1);
	  }


       cout<<"\n\n\tAre you Sure you want to Close your Account? (Y/N): ";
	  we:
	  l=getch();
	  if(l=='n'||l=='N')
	   {cout<<"\n\n\tAccount Not Closed!\n\n\tPress any key to return";
	    getch();
	    delay(1000);
	    login(pos);
	   }
	  else if(l=='y'||l=='Y')
	   {
	    cout<<"\n\n\tClosing your Account......";
	    delay(3000);
	    flag=1;
	    cout<<"\n\n\tAccount Closed!! \n";
	    cout<<"\n\tCollect your balance of Rs. "<<current_amt;
	    cout<<"  from Cash Counter !\n";
	    cout<<"\n\n\n\tThank you for Banking with us !!!\n";


	  for(int i=0;i<count;i++)
	  {long j=fin3.tellg();
	   fin3.read((char *)&uv, sizeof(uv));
	   if(j!=pos)
	   fout2.write((char *)&uv, sizeof(uv));
	  }
       }

       else
       {cout<<"\n\n\tInvalid Choice, Please Enter Again";
	goto we;}

	if(flag==1)
	count--;

	 fout2.close();
	 fin3.close();
	 remove("uvbank.dat");
	 rename("temp.dat","uvbank.dat");


       delay(2000);
       cout<<"\n\n\tPress any key to return!: ";
       getch();
       delay(1000);
       mainmenu();
}

    void uv_bank::update_acc()
{
       clrscr();
       char l,ch,u;

       o:
       clrscr();
       cout<<"\n\n\n\tChoose the detail you want to Update!\n\n";
       cout<<"\t1.Customer Name \n\t2.Mobile No. \n\t3.Address";
       cout<<"\n\n\n\tPress Any Other Key To Save Details\n\n";
       ch=getch();

       switch(ch)
       {
	case '1':
	 {
	  cout<<"\n\t   Press R to Update existing Name ";
	  cout<<"\n\n\t   Press any other key to retain Old name as :";
	  for(int i=0;i<strlen(cus_name);i++)
	  putchar(cus_name[i]);
	  l=getch();
	  if(l=='r'||l=='R')
	  {
	   cout<<"\n\n\t   Enter New Name: ";
	   gets(cus_name);
	   cout<<"\n\n\n\t Customer Name Updated Successfuly ";}
	   delay(1000);
	   cout<<"\n\n\tPress 'R' to Return to Update Menu\n";
	   cout<<"\n\n\tPress Any Other Key To Save Updated Details";
	   u=getch();
	    if(u=='R'||u=='r')
	     {delay(1000);
	      goto o;}

	 break;
	 }
	case '2':
	 {
	  cout<<"\n\t   Press R to Update existing Mobile No.! ";
	  cout<<"\n\n\t   Press any other key to retain Old Mobile No. as :";
	  for(int i=0;i<10;i++)
	  putchar(mobile_no[i]);
	  l=getch();
	  if(l=='r'||l=='R')
	  {
	   cout<<"\n\n\t   Enter New Mobile No.: ";
	   for(int i=0;i<10;i++)
	   mobile_no[i]=getche();
	   cout<<"\n\n\n\tMobile No. Updated Succesfully";}
	   delay(1000);

	   cout<<"\n\n\tPress 'R' to Return to Update Menu\n";
	   cout<<"\n\n\tPress Any Other Key To Save Updated Details";
	   u=getch();
	    if(u=='R'||u=='r')
	     {delay(1000);
	      goto o;}

	 break;
	 }
	case '3':
	 {
	  cout<<"\n\t   Press R to Update existing Address! ";
	  cout<<"\n\n\t   Press any other key to retain Old Address as:"<<address;
	  l=getch();
	  if(l=='r'||l=='R')
	  {
	   cout<<"\n\n\t   Enter New Address: ";
	   gets(address);
	   cout<<"\n\n\n\tAddress Updated Successfully\n\n";}
	   delay(1000);
	   cout<<"\n\n\tPress 'R' to Return to Update Menu\n";
	   cout<<"\n\n\tPress Any Other Key To Save Updated Details";
	   u=getch();
	    if(u=='R'||u=='r')
	     {delay(1000);
	      goto o;}

	 break;
	 }

	default:
	 {
	  clrscr();
	  goto op;
	 }
       }
      op:
      delay(1000);
      cout<<"\n\n\tUpdating Account Details....";
      delay(2500);
      clrscr();
      cout<<"\n\n\n\tDetails Updated Successfully!!!\n\n\tUpdated Details are: \n\n";
      cout<<"\n\tCustomer Name : \n\t";
      puts(cus_name);
      cout<<"\n\n\tMobile Number : \n\t";
      for(int i=0;i<10;i++)
      putchar(mobile_no[i]);
      cout<<"\n\n\tAddress       : \n\t"<<address;

      fstream fio("uvbank.dat",ios::binary|ios::in|ios::out);

       if(!fio)
       {
	cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
	cout<<"\tPlease try again later";
	delay(4000);
	exit(1);
       }
       fio.seekg(pos);
       fio.read((char *)&uvn, sizeof(uvn));
       strcpy(uvn.cus_name,cus_name);
       strcpy(uvn.address,address);
       strcpy(uvn.mobile_no,mobile_no);
       fio.seekp(pos);
       fio.write((char*)&uvn,sizeof(uvn));
       fio.close();
       delay(1500);
      cout<<"\n\n\n\tPress any key to return to Main Screen!\n";
      getch();
      delay(1000);
      login(pos);

}

    void uv_bank::showinfo()
      {
       cout<<"\n\tCustomer Details are:\n\n";
       delay(2000);
       cout<<"\n\n\tCustomer Name: ";
       for(int i=0;i<strlen(cus_name);i++)
       putchar(cus_name[i]);
       delay(1000);
       cout<<"\n\n\tMobile No.: ";
       for(i=0;i<10;i++)
	{putchar(mobile_no[i]);}
       delay(1000);
       cout<<"\n\n\tAddress: ";
       puts(address);
       delay(1000);
       cout<<"\n\tAge : "<<age;
       delay(1000);
       cout<<"\n\n\tAadhar No.: ";
       for(i=0;i<12;i++)
       putchar(aadhar_no[i]);
       delay(1000);
       cout<<"\n\n\tDOB: "<<dd<<" / "<<mm<<" / "<<yyyy;
       delay(1000);
       cout<<"\n\n\tGender: "<<gender;
       delay(1000);
       cout<<"\n\n\tNo. Of Transactions :"<<trans;
       delay(1000);
       if(trans>0)
	{cout<<"\n\n\tPress 'P' To View Your Passbook";
	 cout<<"\n\tPress Any Other Key To Continue";
	 char e=getch();
	 if(e=='p'||e=='P')
	 {clrscr();
	  passbook_det();
	  clrscr();}
	 }
       if(loan_type!='N')
       {cout<<"\n\n\tPress 'L' To View Your Loan Details";
	cout<<"\n\n\tPress Any Other Key To Continue";
	char yuv;
	yuv=getch();
	if((yuv=='l')||(yuv=='L'))
	 {delay(1000);
	  clrscr();
	  loan_details();
	  delay(2000);
	  cout<<"\n\n\tPress Any Key To Continue";
	  getch();
	  clrscr();
	 }
	}
       cout<<"\n\n\n\tAccount No. : "<<acc_no;
       delay(1500);
       cout<<"\n\n\tPassword is : ";
       for(i=0;i<10;i++)
       putchar(password[i]);
       delay(1500);

}
    void uv_bank::withdraw()
{
       clrscr();
       double g;

       cout<<"\n\n\n\tYour Present Balance is: "<<current_amt;
       r:
       cout<<"\n\n\tEnter Amount to be Withdrawn: ";
       cin>>g;
       if(g<0)
       {cout<<"\n\n\tInvalid Value\n\n";
	goto r;}
       if(g>current_amt)
       {cout<<"\n\n\tInsufficient Funds\n\n";
	goto r;}
	else
	{cout<<"\n\n\tWithdrawing Money.......";
	delay(2000);
	cout<<"\n\n\tRs. "<<g<<"  Withdrawn";
	current_amt-=g;
	cout<<"\n\n\tNow Your Current Balance Is :  Rs. "<<current_amt;
	passbook[trans][0]=(-1)*g;
	passbook[trans][1]=current_amt;
	trans++;
	delay(1000);
	cout<<"\n\n\n\tKindly Collect Cash From Cash Counter";
	}

	fstream fio2("uvbank.dat",ios::in|ios::out|ios::binary);

       if(!fio2)
       {
	cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
	cout<<"\tPlease try again later";
	delay(4000);
	exit(1);
	}
	fio2.seekg(pos);
	fio2.read((char*)&uvn, sizeof(uvn));
	uvn.current_amt=current_amt;
	uvn.passbook[uvn.trans][0]=passbook[trans-1][0];
	uvn.passbook[uvn.trans][1]=passbook[trans-1][1];
	uvn.trans=trans;
	fio2.seekp(pos);
	fio2.write((char*)&uvn, sizeof(uvn));
	fio2.close();
	delay(2000);
	cout<<"\n\n\n\tPress Any Key to Return";
	getch();
	delay(1500);
	login(pos);
}

void uv_bank::deposit()
      {
       clrscr();
       double g;
	cout<<"\n\n\n\tYour Present Balance is: "<<current_amt;
	cout<<"\n\n\tEnter Amount to be Deposited (Max 50,00,000 ) : ";
	pk:
	cin>>g;
	if(g>5000000)
	 {cout<<"\n\n\tAmount To High\n\n\tPlease Enter Again : ";
	  goto pk;}
	if(g<0)
	 {cout<<"\n\n\tInvalid Value\n\n\tPlease Enter Again : ";
	  goto pk;}
	cout<<"\n\n\tDepositing Money.......";
	delay(2000);
	cout<<"\n\n\tRs. "<<g<<" deposited\n\n";
	current_amt+=g;
	cout<<"\n\tNow, Current Balance is "<<current_amt;

	passbook[trans][0]=g;
	passbook[trans][1]=current_amt;
	trans++;

	fstream fio3("uvbank.dat",ios::in|ios::out|ios::binary);

       if(!fio3)
       {
	cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
	cout<<"\tPlease try again later";
	delay(4000);
	exit(1);
	}

	fio3.seekg(pos);
	fio3.read((char*)&uvn, sizeof(uvn));
	uvn.current_amt=current_amt;
	uvn.passbook[uvn.trans][0]=passbook[trans-1][0];
	uvn.passbook[uvn.trans][1]=passbook[trans-1][1];
	uvn.trans=trans;
	fio3.seekp(pos);
	fio3.write((char*)&uvn, sizeof(uvn));
	fio3.close();
	delay(1500);
	cout<<"\n\n\n\tPress Any Key to Return";
	getch();
	delay(1500);
	login(pos);
}


void uv_bank::transfer()
{
      clrscr();
      long money;
      long s;
      int flag=0;

      cout<<"\n\n\n\tYour Current Balance Is : "<<current_amt;
      delay(1000);
      f:
      cout<<"\n\n\n\tEnter amount to be transferred (Max: 50,00,000) : ";
      gk:
      cin>>money;
     if(money>5000000)
      {cout<<"\n\n\tAmount Too High\n\n\tPlease Enter Amount Again : ";
       goto gk;}
     if(money<0)
      {cout<<"\n\n\tInvalid Value\n\n\tPlease Enter Amount Again : ";
       goto gk;}
     if(money>current_amt)
      {
       cout<<"\n\tInsufficient Account Balance!\n";
       cout<<"\n\tPress 'R' to Re-Enter Amount\n\n\tPress Any Other Key To Return";
       char vb;
       vb=getch();
       if((vb=='r')||(vb=='R'))
       goto f;
       else
       {delay(1000);
	login(pos);
       }
      }
      j:
      fstream fio4("uvbank.dat",ios::in|ios::out|ios::binary);

      if(!fio4)
       {
	cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
	cout<<"\tPlease try again later";
	delay(4000);
	exit(1);
	}
      fio4.seekg(0);

      cout<<"\n\n\n\tEnter Account No. of Beneficiary: ";
      cin>>s;
      long posn;
      for(int i=0;i<count;i++)
      {posn=fio4.tellg();
       fio4.read((char *)&uvr, sizeof(uvr));
       if(s==uvr.acc_no)
	{
	 uvr.current_amt+=money;
	 uvr.passbook[uvr.trans][0]=money;
	 uvr.passbook[uvr.trans][1]=uvr.current_amt;
	 uvr.trans++;
	 flag=1;
	 fio4.seekp(posn);
	 fio4.write((char *)&uvr, sizeof(uvr));
	 break;
	}
       }

       if(flag==1)
	{
	fio4.seekg(pos);
	fio4.read((char *)&uvn, sizeof(uvn));
	current_amt-=money;
	uvn.current_amt=current_amt;
	passbook[trans][0]=(-1)*money;
	passbook[trans][1]=current_amt;
	uvn.passbook[uvn.trans][0]=(-1)*money;
	uvn.passbook[uvn.trans][1]=uvn.current_amt;
	trans++;
	uvn.trans=trans;

	fio4.seekp(pos);
	fio4.write((char *)&uvn, sizeof(uvn));
	fio4.close();

	 cout<<"\n\n\n\tTransferring Rs. "<<money<<" to Account No. "<<s<<" ......";
	 delay(3000);
	 cout<<"\n\n\tMoney Transferred Successfuly !!!\n";
	 delay(1000);
	 cout<<"\n\n\tPress Any Key to Return \n";
	 getch();
	 delay(1000);
	 login(pos);
	}
	else
	 {
	 cout<<"\n\n\n\tAccount No. does not Exist !!!";
	 delay(1500);
	 cout<<"\n\n\n\tPress A to Enter Again\n\n\t";
	 cout<<"Press Any Other Key To Return";
	 char h;
	 h=getch();
	   if(h=='A'||h=='a')
	   goto j;
	   else
	   fio4.close();
	   delay(1000);
	   login(pos);
	 }
 }

void uv_bank::req_loan()

{clrscr();
 cout<<"\n\n\n\tFor Requesting For A Loan , You Must :";
 delay(1000);
 cout<<"\n\n\n\t  * Have Rs. 5000 in Your Account";
 cout<<"\n\n\t  * Be Atleast 18 Years Old";
 cout<<"\n\n\t  * Should Not Be Having A Loan Already";
 delay(1500);
 cout<<"\n\n\n\n\tPress Any Key To Check Your Eligibility\n";
 getch();
  clrscr();

 fstream fio5("uvbank.dat",ios::in|ios::out|ios::binary);

      if(!fio5)
       {
	cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
	cout<<"\tPlease try again later";
	delay(4000);
	exit(1);
	}
   fio5.seekg(pos);
   fio5.read((char*)&uvn,sizeof(uvn));

  cout<<"\n\n\n\tChecking Your Eligibility ......";
  delay(1500);
  if(uvn.loan_type!='N')
  {clrscr();
   cout<<"\n\n\n\tYou Already Have A Loan !!!";
   cout<<"\n\n\n\tClear Your Existing Loan To Request For A New One";
   delay(1000);
   cout<<"\n\n\n\tPress Any Key To Return";
   getch();
   delay(1000);
   login(pos);}
  if((uvn.current_amt>=5000)&&(uvn.age>=18))
   {cout<<"\n\n\n\tYou Are Eligible For Requesting For A Loan !!!";
    cout<<"\n\n\n\tPress Any Key To View Loan Options";
    getch();}
   else
   {cout<<"\n\n\n\tYou Are  NOT  Eligible For Requesting For A Loan !!!";
    cout<<"\n\n\n\tPress Any Key To Return";
    getch();
    delay(1000);
    login(pos);}

  clrscr();
  cout<<"\n\n\n\t1. Simple Interest";
  cout<<"\n\n\t  * Rate For Males : 9.6 % p.a.\n\n\t";
  cout<<"  * Rate For Females : 7.8 % p.a.\n\n\t  * Rate For Senior Citizens : 6.4 % p.a.";
  cout<<"\n\n\n\n\t2. Compund Interest";
  cout<<"\n\n\t  * Rate For Males : 8.2 % p.a.\n\n\t";
  cout<<"  * Rate For Females : 6.8 % p.a.\n\n\t  * Rate For Senior Citizens : 5.4 % p.a.";
  delay(2000);
  char ch3;
  dl:
  cout<<"\n\n\n\tEnter Required Loan Type";
  ch3=getch();

  if(ch3=='1')
   uvn.loan_type='S';
  else if(ch3=='2')
   uvn.loan_type='C';
  else
   {cout<<"\n\n\n\tIncorrect Choice\n\tPlease Enter Again ";
    goto dl;}
  delay(1000);
  clrscr();
 cout<<"\n\n\n\tEnter Principle Amount ( Between 10,000 & 50,00,000 )\n\n\t";
 yu:
 cin>>uvn.principle;
  if((uvn.principle>5000000)||(uvn.principle<10000))
   {cout<<"\n\n\tInappropriate Value\n\n\tPlease Enter Again : ";
    goto yu;}
  uvn.passbook[uvn.trans][0]=uvn.principle;
  uvn.passbook[uvn.trans][1]=uvn.principle+uvn.current_amt;
  uvn.trans++;
   cout<<"\n\n\n\tEnter Repay Time In Years (From 1 to 10 ) : ";
   gb:
   cin>>uvn.time;
   if((uvn.time>10.0)||(uvn.time<1.0))
   {cout<<"\n\n\tInappropriate Value\n\n\tPlease Enter Again : ";
    goto gb;}
   if(uvn.loan_type=='S')
     {
      if(uvn.age>=60)
       uvn.rate=6.4;
      else if(uvn.gender=='F')
       uvn.rate=7.8;
      else
       uvn.rate=9.6;
      }
   else
     {
      if(uvn.age>=60)
       uvn.rate=5.4;
      else if(uvn.gender=='F')
       uvn.rate=6.8;
      else
       uvn.rate=8.2;
      }
  if(uvn.loan_type=='S')
   {uvn.interest= (uvn.principle*uvn.time*uvn.rate)/100;
    uvn.loan_amt=uvn.principle+uvn.interest;
    uvn.no_of_EMI=uvn.time*12;
    uvn.EMI= uvn.loan_amt/uvn.no_of_EMI;
    }
  else
   {
    uvn.loan_amt= uvn.principle*(pow((1+(uvn.rate/100)),uvn.time));
    uvn.interest= uvn.loan_amt-uvn.principle;
    uvn.no_of_EMI=uvn.time*12;
    uvn.EMI= uvn.loan_amt/uvn.no_of_EMI;
    }
   fio5.seekp(pos);
   fio5.write((char*)&uvn,sizeof(uvn));

 delay(1000);
 clrscr();
 delay(500);
 uvn.loan_details();
 fio5.close();
 delay(2000);
 cout<<"\n\n\n\tPress Any Key To Return ";
 getch();
 delay(1000);
 login(pos);
}

void uv_bank::loan_details()

{
  if((loan_type!='S')&&(loan_type!='C'))
  {cout<<"\n\n\n\tYou Have Not Taken A Loan !";
   }
 else
 {
 cout<<"\n\n\n\tYour Loan Details Are : ";
 delay(500);
 cout<<"\n\n\n\t   Loan Type : ";
  if(loan_type=='S')
  cout<<"Simple";
  else if(loan_type=='C')
  cout<<"Compound";
   cout<<"\n\n\t   Principle Amount : INR "<<principle;
   cout<<"\n\n\t   Interst Is : INR "<<interest;
   cout<<"\n\n\t   Total Amount To Be Returned : INR "<<loan_amt;
   cout<<"\n\n\t   Time Granted To Return : "<<time<<"  Years";
   cout<<"\n\n\t   Number Of EMIs : "<<no_of_EMI;
   cout<<"\n\n\t   EMI Amount : INR "<<EMI;

   }
}

void mainmenu()
{
     clrscr();

     char b[10],choice1;
     int flag,a2,i;
     long a;

     cout<<"\n\n\n\t\t\t\t * * * UV BANK * * *\n\n\n";
     cout<<"\n\t\tWelcome Customer!!\n\n\n\n";
     cout<<"\t1. Log In\n";
     cout<<"\n\t2. New Customer\n";
     cout<<"\n\t3. About Us\n";
     cout<<"\n\t4. Contact Us\n";
     cout<<"\n\t5. Exit\n\n";

     delay(1000);
     cout<<"\n\tEnter Your Choice: ";
     choice1=getche();

       switch(choice1)
       {
	 case '1':
	    {
	     clrscr();
	     if(count==0)
	      {cout<<"\n\n\n\tLogin Not Possible As";
	       cout<<" No Accounts Exist Yet";
	       cout<<"\n\n\n\tPress Any Key To Return";
	       getch();
	       delay(1000);
	       mainmenu();}
	     cout<<"\n\n\n\tEnter Account No.: ";
	     cin>>a;
	     cout<<"\n\n\tEnter Password: ";
	     for(i=0;i<10;i++)
	       {b[i]=getch();
		cout<<"*";}
	     flag=uv.check(a,b);

	       if(flag==3)
	       {clrscr();
		delay(1000);
		cout<<"\n\n\n\t\tLogin Successful  !!!\n";
		delay(2500);
		login(pos);
		}
		else if(flag==2)
		{delay(1000);
		 cout<<"\n\n\n\tIncorrect Password !!!";
		 sound(8000);
		 delay(2000);
		 nosound();
		 mainmenu();
		 }
		 else if(flag==0)
		{
		 delay(1500);
		 cout<<"\n\n\n\tAccount Does Not Exist !!!";
		 delay(2000);
		 mainmenu();
		}
		else
		{cout<<"\n\n\n\tOops, Something Went Wrong";
		 delay(2500);
		 exit(0);}

		   break;
	    }
	 case '2':
	    {
	     uv.new_acc();
	     delay(2000);
	     clrscr();
	     cout<<"\n\n\n\tPress Any Key To Return";
	     getch();
	     mainmenu();
	     break;
	    }
	 case '3':
	    {
	     clrscr();
	     delay(1000);
	     cout<<"\n\n\n\n\tABOUT US:\n\n\n";
	     delay(1000);
	     cout<<"\n\tUV Bank has been a Renowned Name in the";
	     cout<<"\n\tWorld of Banking for more than 2 Decades.\n";
	     delay(1000);
	     cout<<"\n\tWe Promise you the Best Banking Experiance";
	     cout<<"\n\tyou can ever have Along with High Levels of";
	     cout<<"\n\tSecurity & Fast Services, Which Helps you";
	     cout<<"\n\tto Bank Smoothly with Trust & Confidence.";
	     delay(1000);
	     cout<<"\n\n\n\tPlese Allow Us To Faithfully Serve You.";
	     delay(2000);
	     cout<<"\n\n\n\t\t\t\t\tuvbank pvt.ltd.(regd)";

	     delay(4000);
	     cout<<"\n\n\n\t ";
	     cout<<"Press any key to return";
	     getch();
	     mainmenu();
	    }
	 case '4':
	    {
	     clrscr();
	     delay(1000);
	     cout<<"\n\n\n\tContact Us :\n";
	     delay(1000);
	     cout<<"\n\n    Mobile :\t\t   9999999999";
	     cout<<"\n\n\n    Phone :\t\t   011-88888888";
	     cout<<"\n\n\n    e mail ID :\t\t   yuvrajchakraverty@gmail.com";
	     delay(3000);
	     cout<<"\n\n\n\n\tPress Any Key to Return";
	     getch();
	     mainmenu();
	    }
	 case '5':
	    {clrscr();
	    cout<<"\n\n\n\tExiting .....";
	    delay(2000);
	    exit(0);
	    }
	 default:
	    {
	    cout<<"\n\n\tWrong Choice!\n";
	    cout<<"\n\tPress any key to return";
	    getch();
	    mainmenu();
	    }
       }
}

void login(long pos)
{
     clrscr();
     char choice2;
	  ifstream fin("uvbank.dat",ios::in|ios::binary);
	  if(!fin)
	      {
	       cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
	       cout<<"\tPlease try again later";
	       delay(4000);
	       exit(1);
	      }
	  fin.seekg(pos);
	  fin.read((char*)&uv,sizeof(uv));

	  cout<<"\n\n\tWelcome  "<<uv.get_cusname();
	  delay(1000);
	  cout<<"\n\n\tYour Current Balance Is :  Rs. "<<uv.get_balance();
	  delay(1000);

	  cout<<"\n\n\n";
	  cout<<"\ta. View Personal Details\n";
	  cout<<"\tb. View Passbook\n";
	  cout<<"\tc. Update Personal Details\n";
	  cout<<"\td. Transfer Money\n";
	  cout<<"\te. Deposit Money\n";
	  cout<<"\tf. Withdraw Money\n";
	  cout<<"\tg. View Your Loan Details\n";
	  cout<<"\th. Request For Loan\n";
	  cout<<"\ti. Change Password\n";
	  cout<<"\tj. Clear Passbook\n";
	  cout<<"\tk. Clear Loan\n";
	  cout<<"\tl. Close Account\n";
	  cout<<"\tm. Log Out\n";
	  cout<<"\tn. Exit\n\n";
	  delay(1000);

	  cout<<"\n\tEnter Your Choice: ";

	  choice2=getch();
	  choice2=toupper(choice2);


		  if(choice2=='A')
		   {clrscr();
		    delay(1000);
		    uv.showinfo();
		    cout<<"\n\n\n\tPress any key to return\n\n\t ";
		    getch();
		    delay(1000);
		    login(pos);}
		  else if(choice2=='B')
		   {uv.passbook_det();
		    cout<<"\n\n\tPress Any Key To Return";
		    getch();
		    delay(1000);
		    login(pos);}
		  else if(choice2=='C')
		   uv.update_acc();
		  else if(choice2=='D')
		    uv.transfer();
		  else if(choice2=='E')
		   uv.deposit();
		  else if(choice2=='F')
		   uv.withdraw();
		  else if(choice2=='G')
		   {delay(1000);
		    clrscr();
		    uv.loan_details();
		    delay(1500);
		    cout<<"\n\n\n\tPress Any Key To Return";
		    getch();
		    login(pos);}
		  else if(choice2=='H')
		   uv.req_loan();
		  else if(choice2=='I')
		   uv.change_pass();
		  else if(choice2=='J')
		   uv.refresh_passbook();
		  else if(choice2=='K')
		   uv.refresh_loan();
		  else if(choice2=='L')
		   uv.close_acc();
		  else if(choice2=='M')
		   {delay(1000);
		    mainmenu();}
		  else if(choice2=='N')
		   {clrscr();
		    cout<<"\n\n\n\tExiting.....";
		    delay(2000);
		    exit(0);}
		  else
		   {clrscr();
		    cout<<"\n\n\tWrong Choice !\n";
		    cout<<"\n\tPress Any Key To Enter Again\n";
		    getch();
		    delay(500);
		    login(pos);
		   }

}

void uv_bank::change_pass()

{ clrscr();

      delay(1000);
      cout<<"\n\n\n\tYour Current Password is : ";
      for(int i=0;i<10;i++)
      putchar(password[i]);
      delay(1500);
      cout<<"\n\n\n\tEnter New Password :  ";
      fo:
      for(i=0;i<10;i++)
      {password[i]=getche();}
      cout<<"\n\n\n\tPress 'C' To Confirm New Password";
      cout<<"\n\n\tPress Any Other Key To Re-Enter Password";
      char w;
      w=getch();
      if(w=='C'||w=='c')
      {goto jg;}
      else
       {cout<<"\n\n\n\tRe-Enter Password : ";
	goto fo;}
     jg:
     delay(800);
     cout<<"\n\n\n\tPassword Changed Successfully";

     fstream fio("uvbank.dat",ios::in|ios::out|ios::binary);

      if(!fio)
       {
	cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
	cout<<"\tPlease try again later";
	delay(4000);
	exit(1);
	}

      fio.seekg(pos);
      fio.read((char *)&uvn,sizeof(uvn));
      strcpy(uvn.password,password);
      fio.seekp(pos);
      fio.write((char*)&uvn,sizeof(uvn));
      fio.close();
      delay(1000);
      cout<<"\n\n\n\tPress Any Key To Return";
      getch();
      login(pos);
}

int uv_bank::check(long a, char* b)

{  int flag2=0;

  ifstream fin1("uvbank.dat",ios::in|ios::binary);

	     if(!fin1)
	      {
	       cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
	       cout<<"\tPlease try again later";
	       delay(4000);
	       exit(1);
	      }

	     for(int i=0;i<count;i++)
	      { flag2=0;
		long q=fin1.tellg();
		fin1.read((char *)&uv,sizeof(uv));

	       if(uv.acc_no==a)
		{ flag2=1;
		  for(int j=0;j<10;j++)
		  {if((uv.password[j])!=b[j])
		   flag2=2;
		   break;}
		  if(flag2==1)
		  {pos=q;
		   flag2=3;}
		}
	       if(flag2!=0)
	       break;
	     }
fin1.close();
return flag2;

}

void uv_bank::passbook_det()

{ clrscr();
  if(trans==0)
  {cout<<"\n\n\n\tYour Passbook Is Empty";
   cout<<"\n\n\n\tPress Any Key To Return";
   getch();
   delay(1000);
   login(pos);}
  cout<<"\n\n\tPassbook :";
  delay(1000);
  cout<<"\n\n\tNo. Of Transactions Made: "<<trans;
  delay(1000);
  cout<<"\n\n\n\t    Transaction\t        Balance\n\n";
  for(int i=0;i<trans;i++)
  {delay(1000);
   cout<<"\n\t    ";
   if(passbook[i][0]>0)
    cout<<"+"<<passbook[i][0]<<"\t\t"<<passbook[i][1]<<"\n";
   else
    cout<<passbook[i][0]<<"\t\t"<<passbook[i][1]<<"\n";
  }
  delay(1500);

}

void uv_bank::refresh_passbook()
{
 clrscr();
 fstream fio("uvbank.dat",ios::in|ios::out|ios::binary);
 if(!fio)
 {
 cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
 cout<<"\tPlease try again later";
 delay(4000);
 exit(1);
 }
 fio.seekg(pos);
 fio.read((char*)&uvn,sizeof(uvn));

 for(int i=0;i<uvn.trans;i++)
 {uvn.passbook[i][0]=0;
  uvn.passbook[i][1]=0;
 }
 uvn.trans=0;
 fio.seekp(pos);
 fio.write((char*)&uvn,sizeof(uvn));
 fio.close();
 cout<<"\n\n\n\tClearing Passbook .....";
 delay(2000);
 cout<<"\n\n\n\tPassbook Cleared !";
 cout<<"\n\n\n\tPress Any Key To Return";
 getch();
 delay(1000);
 login(pos);
}

void uv_bank::refresh_loan()

{
 clrscr();
 if(loan_type=='N')
 {cout<<"\n\n\n\tYou Have Not Taken A Loan Yet";
  cout<<"\n\n\n\tPress Any Key To Return";
  getch();
  delay(1000);
  login(pos);}
 cout<<"\n\n\n\tTo Clear Your Loan";
 cout<<"\n\n\tYou Will Have To Pay The Whole Loan Amount";
 cout<<"\n\n\t( Including Interest ) At One Go !";
 delay(1500);
 cout<<"\n\n\n\n\tPress 'R' To Agree";
 cout<<"\n\n\tPress Any Other Key To Return";
 char ty=getch();
 clrscr();
 if(ty=='R'||ty=='r')
  {
   fstream fio("uvbank.dat",ios::in|ios::out|ios::binary);
   if(!fio)
   {
   cout<<"\n\n\tSorry, We Are Facing Some Problem\n";
   cout<<"\tPlease try again later";
   delay(4000);
   exit(1);
   }

   fio.seekg(pos);
   fio.read((char*)&uvn,sizeof(uvn));
   if(uvn.loan_type=='N')
   {cout<<"\n\n\n\tYou Have Not Taken A Loan Yet";
    cout<<"\n\n\n\tPress Any Key To Return";
    getch();
    fio.close();
    delay(1000);
    login(pos);}

   if(uvn.loan_amt>uvn.current_amt)
   {
    cout<<"\n\n\n\tYou Don't Have Sufficient Funds To Repay The Loan";
    cout<<"\n\n\n\tPress Any Key To Return";
    getch();
    fio.close();
    delay(1000);
    login(pos);
    }
   cout<<"\n\n\n\tRepaying Loan.....";
   delay(1500);
   cout<<"\n\n\n\tLoan Cleared !!!";
   uvn.loan_type='N';
   uvn.current_amt-=uvn.loan_amt;
   uvn.passbook[uvn.trans][0]=(-1)*uvn.loan_amt;
   uvn.passbook[uvn.trans][1]=uvn.current_amt;
   uvn.trans++;
   fio.seekp(pos);
   fio.write((char*)&uvn,sizeof(uvn));
   fio.close();
   cout<<"\n\n\n\n\tPress Any Key To Return";
   getch();
   delay(1000);
   login(pos);
  }
 else
 {
  cout<<"\n\n\n\tLoan Not Cleared !";
  cout<<"\n\n\n\tPress Any Key To Return";
  getch();
  delay(1000);
  login(pos);
  }
}
