int isfull()
{
        if(front<rear) 
        return(front+rear==3);
        else if(front>rear) 
        return(front-rear==1);
        else return 0;
}