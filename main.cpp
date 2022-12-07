#include <windows.h>
#include<mmsystem.h>
#include<iostream>
#include<string.h>

using namespace std;

struct node{
    string music;
    struct node *nxt,*prev;
}*fwd,*bwd,*head,*ptr;
string opt;

void gotoxy(short x,short y);

void title();

node* getnode(string song)
{
    struct node *N=new node;
    fwd=N;
    N->music=song;
    N->nxt=NULL;
    N->prev=bwd;
    bwd->nxt=N;
    bwd=fwd;
    return N;
}
void createHead(string song)
{
    struct node*N=new node;
    N->music=song;
    N->nxt=NULL;
    N->prev=NULL;
    head=N;
    fwd=N;
    bwd=N;
}

//This function is to add the playlist songs in your music player

void addMusic()
{
    bwd=head;
    while(bwd->nxt!=NULL)
    {
        bwd=bwd->nxt;
    }
    cout<<"Enter the song you want to insert in your music player: ";
    string song;
    cin>>song;
    struct node*N=new node;
    N->music=song;
    N->nxt=NULL;
    N->prev=bwd;
    bwd->nxt=N;
}

//This function shows what are all the songs avaiable so that the usercan add song to their music list

void musicList()
{
	system("color 3");
	cout<<"\n\t\tPlaylist\n";
	cout<<"\t\t********\n";
	cout<<"1 ->Sirikalam parakalam -Tamil\n";
	cout<<"2 ->Begger - Chinese\n";
	cout<<"3 ->Arjunar Villu- Tamil\n";
	cout<<"4 ->Pavizha Mazha - Tamil\n";
	cout<<"5 ->Kathaipoma - Tamil\n";
	cout<<"6 ->Malarae ninne - Malayalam\n";
	cout<<"7 ->Yar Alaipathu- Tamil\n";
	cout<<"8 ->Arabic Kadaloram - Tamil\n";
	
}

//This function is to display the songs in your own playlist 

void display()
{
    ptr=head;
    while(ptr->nxt!=NULL)
    {
        cout<<ptr->music<<"->";
        ptr=ptr->nxt;
    }
    cout<<ptr->music<<"->";
}

//This function will make the user to search and play music so that it will be helpful for the user.

void searchMusic()
{
	system("color 6F");
    string song;
    cout<<"Enter the song to be searched: ";
    cin>>song;
    ptr=head;
    bool isFound=false;
    bool play =true;
    while(ptr!=NULL)
    {
        if(ptr->music==song)
        {
            isFound=true;
            break;
        }
        else
        {
            ptr=ptr->nxt;
        }
    }
    ptr=head;
    if (isFound==true)
    {
        cout<<"\n\nThe song which you entered has been successfully found!!\n";
		int flag=0;
		do{
        	if(ptr->music==song)
        	{
        		cout<<"\n\nWant to play?   ";
        		string opt;
        		cin>>opt;
        		if(opt!="yes")
				{
					break;
				}
        		
        		if(opt=="yes")
        		{
        			if(ptr->music=="sirikalam")
        			{
						PlaySound(TEXT("sirikalam.wav"),NULL,SND_ASYNC);
        				system("pause");
        			}
        			else if(ptr->music=="begger")
        			{
        				PlaySound(TEXT("begger.wav"),NULL,SND_ASYNC);
        				system("pause");
					}
					else if(ptr->music=="arjunarvillu")
					{
						PlaySound(TEXT("arjunarVillu.wav"),NULL,SND_ASYNC);
        				system("pause");
					}
					else if(ptr->music=="pavizhamazha")
					{
						PlaySound(TEXT("pavizhaMazha.wav"),NULL,SND_ASYNC);
        				system("pause");
					}
					else if(ptr->music=="kathaipoma")
					{
						PlaySound(TEXT("Kadhaippoma.wav"),NULL,SND_ASYNC);
        				system("pause");
					}
					else if(ptr->music=="malaraeninne")
					{
						PlaySound(TEXT("malareNinne.wav"),NULL,SND_ASYNC);
        				system("pause");
					}
					else if(ptr->music=="yarazhaipadhu")
					{
						PlaySound(TEXT("yaarAzhaippadhu.wav"),NULL,SND_ASYNC);
        				system("pause");
					}
					else if(ptr->music=="arabickadaloram")
					{
						PlaySound(TEXT("arabicKadaloram.wav"),NULL,SND_ASYNC);
        				system("pause");
					}
        		}
        	}
        	else
        	{
        		ptr=ptr->nxt;
        	}
        	if(opt=="yes")
			{
        		cout<<"\n\nWant to stop? ";
        		string st;
        		cin>>st;
        		if(st=="yes")
        		{ 
        			
        			PlaySound(NULL,0,0);
        			break;
				}
			}	
        	
   		}while(flag=1);
	}
   	else
   	{
        cout<<"\nOops!!No such song!!\n";
        cout<<"\nWanna go to main menu? ";
        cin>>opt;	
	}
}

//This function is to delete the appropriate song which user want to delete

void deleteMusic()
{
	cout<<"Enter the song which you want to delete : ";
	string song;
    cin>>song;
    ptr=head;
    bool isFound = false;
    while(ptr->nxt!=NULL)
    {
       	if(ptr->music==song)
		{
       		isFound=true;
    		break;
    	}
	 	ptr=ptr->nxt;
	}
	if(isFound)
	{
		ptr->prev->nxt=ptr->nxt;
		ptr->nxt->prev=ptr->prev;
		struct node *temp=ptr;
		delete (temp);
	}
	else
	{
		cout<<"\n\nOops!!No such song in your playlist!!!\n";
		cout<<"\n\nWanna switch to main menu ? ";
		cin>>opt;
	}
}

//To play music continuously

void myPlayList()
{
        cout<<"Now playing Sirikalam Parakalam song_Tamil\n";
        PlaySound(TEXT("sirikalam.wav"),NULL,SND_ASYNC);
        cout<<"\n\nWanna switch to nxt song?  ";
        cin>>opt;
        if(opt=="yes")		
        	PlaySound(NULL,0,0);
        title();
        cout<<"Now playing Begger_chinese\n";
        PlaySound(TEXT("begger.wav"),NULL,SND_ASYNC);
        cout<<"\n\nWanna switch to nxt song?  ";
        cin>>opt;
        if(opt=="yes")		
        	PlaySound(NULL,0,0);
        title();
        cout<<"Now playing Arjunar Villu_Tamil\n";
        PlaySound(TEXT("arjunarVillu.wav"),NULL,SND_ASYNC);
        cout<<"\n\nWanna switch to nxt song?  ";
        cin>>opt;
        if(opt=="yes")		
        	PlaySound(NULL,0,0);
        title();
        cout<<"Now playing Pavizha Mazha_Tamil\n";
        PlaySound(TEXT("pavizhaMazha.wav"),NULL,SND_ASYNC);
        cout<<"\n\nWanna switch to nxt song?  ";
        cin>>opt;
        if(opt=="yes")		
        	PlaySound(NULL,0,0);
        title();
        cout<<"Now playing Kathaipoma_Tamil\n";
        PlaySound(TEXT("Kadhaippoma.wav"),NULL,SND_ASYNC);
        cout<<"\n\nWanna switch to nxt song?  ";
        cin>>opt;
        if(opt=="yes")		
        	PlaySound(NULL,0,0);
        title();
        cout<<"Now playing Malarae ninae_Malayalam\n";
        PlaySound(TEXT("malareNinne.wav"),NULL,SND_ASYNC);
        cout<<"\n\nWanna switch to nxt song?  ";
        cin>>opt;
        if(opt=="yes")		
        	PlaySound(NULL,0,0);
        title();
        cout<<"Now playing Yar alaipathu_Tamil\n";
        PlaySound(TEXT("yaarAzhaippadhu.wav"),NULL,SND_ASYNC);
		cout<<"\n\nWanna switch to main menu?  ";
        cin>>opt;
        if(opt=="yes")		
        	PlaySound(NULL,0,0);
        
}

//This function is to play music by giving options to the user .


void playMusic()
{
    string ch;

    do {
    title();
    musicList();
    cout<<"\n\n\t\tEnter the song you want to play: ";
    int n;
    cin>>n;
    system("cls");
    title();
    system("color 3F");
    switch(n)
    {
    case 1:
        cout<<"Now playing Sirikalam Parakalam song_Tamil\n";
        PlaySound(TEXT("sirikalam.wav"),NULL,SND_ASYNC);
        system("pause");
        break;
    case 2:
        cout<<"Now playing Begger_chinese\n";
        PlaySound(TEXT("begger.wav"),NULL,SND_ASYNC);
        system("pause");
        break;
    case 3:
        cout<<"Now playing Arjunar Villu_Tamil\n";
        PlaySound(TEXT("arjunarVillu.wav"),NULL,SND_ASYNC);
        system("pause");
        break;
    case 4:
        cout<<"Now playing Pavizha Mazha_Tamil\n";
        PlaySound(TEXT("pavizhaMazha.wav"),NULL,SND_ASYNC);
        system("pause");
        break;
    case 5:
        cout<<"Now playing Kathaipoma_Tamil\n";
        PlaySound(TEXT("Kadhaippoma.wav"),NULL,SND_ASYNC);
        system("pause");
        break;
    case 6:
        cout<<"Now playing Malarae ninae_Malayalam\n";
        PlaySound(TEXT("malareNinne.wav"),NULL,SND_ASYNC);
        system("pause");
        break;
    case 7:
        cout<<"Now playing Yar alaipathu_Tamil\n";
        PlaySound(TEXT("yaarAzhaippadhu.wav"),NULL,SND_ASYNC);
        system("pause");
        break;
    case 8:
        cout<<"Now playing Arabic Kadaloram_Tamil\n";
        PlaySound(TEXT("arabicKadaloram.wav"),NULL,SND_ASYNC);
        system("pause");
        break;
    default:
    	cout<<"\nEnter appropriate number!!\n\n";

    }
    cout<<"\n\nwant to continue? ";
	PlaySound(NULL,0,0);
    cin>>ch;
    }while(ch=="yes");
}

//This function is to move or place the content at the respective co-ordinates

void gotoxy(short x,short y)
{
    COORD pos={x,y};//declaring co ordinates in (x,y);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

//This function is to get exited from the music player

void exit()
{
	system("cls");
	system("color 5A");
	gotoxy(40,10);
	cout<<"   :) !THANK YOU FOR USING OUR MUSIC PLAYER! :)\n\n\n";
}

//This function is for title block

void title()
{
	//gotoxy(8,0);
	system("cls");
	cout<<"\n\n\n\n\t\t\t\t-*-*-*-*-*-*-*-*-*-\n\n";
	cout<<"\t\t\t\tJEERAS MUSIC PLAYER\n\n";
	cout<<"\t\t\t\t-*-*-*-*-*-*-*-*-*-\n\n";
}

//This function is to create a menu option, so that it would be user-friendly.

void mainMenu()
{
   system("cls");
   system("color 2F");
   int n,op;
   title();
   gotoxy(90,8);
   cout<<"\n\t\tMAIN MENU\n";
   cout<<"\t\t**** ****\n\n";
   cout<<"\t1. To Add Music To Your Playlist\n\n";
   cout<<"\t2. To Display your musiclist\n\n";
   cout<<"\t3. To Play Music\n\n";
   cout<<"\t4. To Search And Play Music\n\n";
   cout<<"\t5. To Play songs continuously\n\n";
   cout<<"\t6. To Delete A Song from Your Playlist\n\n";
   cout<<"\t7. To Exit\n";
   gotoxy(12,28);
   cout<<"Enter the option you want to do: ";
   cin>>n;
   switch(n)
   {
   		case 1:
   			title();
   			addMusic();
   			mainMenu();
   			break;
   		case 2:
   			title();
   			musicList();
   			cout<<"\n\n\t\t\tWanna switch to main menu? ";
			cin>>opt;
   			mainMenu();
   			break;
   		case 3:
   			title();
   			playMusic();
   			mainMenu();
   			break;
   		case 4:
   			title();
   			searchMusic();
   			mainMenu();
   			break;
   		case 5:
   			title();
   			myPlayList();
   			mainMenu();
   			break;
   		case 6:
   			title();
   			deleteMusic();
   			mainMenu();
   		case 7:
   			exit();
   			break;
   		default:
   			cout<<"\n\t\tEnter appropriate option!!!\n";
   	}

}

int main()
{
   createHead("sirikalam");
   getnode("begger");
   mainMenu();
   display();
}
