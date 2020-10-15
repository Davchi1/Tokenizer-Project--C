#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Prints out a word token
int getWordToken(char* temp, int start){
    int x = start;
    int count = 0;
     if(x<=strlen(temp)-6&&temp[x]=='s'&&temp[x+1]=='i'&&temp[x+2]=='z'&&temp[x+3]=='e'&&temp[x+4]=='o'&&temp[x+5]=='f'){
         if(x<strlen(temp)-7){
             if(isalpha(temp[x]+7)){
                {}
             }
             else{
            printf("sizeof sizeof\n");
            return 5;

             }
             
         }
        

    }
    // Goes through the string, looks to see how big the word is. Count gives us an index to stop at.
    for(;x<strlen(temp);++x){
        if(isalpha(temp[x])||isdigit(temp[x])){
            count+=1;
        }
        else{
            break;
        }
    }
    //("%d\n",count);
    char* wordToken;
    wordToken = (char *)malloc(count * sizeof(char));

    
    int j=0;
    while(j<count){
        wordToken[j]=temp[start+j];
        j++;
    }
  //  printf("WorkTokenLength: %ld",strlen(wordToken));

    //printf("%s",wordToken);
    printf("WORD:%s\n",wordToken);
    free(wordToken);
    return count;


}
int getHexidecimalToken(char*temp,int start){
    int x = start;
    int count = 0;
    for(;x<strlen(temp);++x){
        if(isxdigit(temp[x])||isalpha(temp[x])){
            count+=1;
        }
        else{
            break;
        }
    }
    char* hexToken;
    hexToken = (char*)malloc(sizeof(char)*count);

    int j =0;
    while(j<count){
        hexToken[j]=temp[start+j];
        j++;
    }
    printf("HEXIDECIMAL INTEGER %s\n",hexToken);
    free(hexToken);
    return count;
}
//Prints out a floating decimal token
 int getFloatingdecimalToken(char*temp,int start){
    _Bool anothaONE = 1;
    int x = start;
   
    int count = 0;
    for(;x<strlen(temp);++x){
        if(isdigit(temp[x])||temp[x]=='.'){
            count+=1;
        }
        else{
            break;
        }
    }
    printf("%d",count);
    char* floatToken;
    floatToken = (char*)malloc(sizeof(char)*count);
    int j =0;
    while(j<count){
        floatToken[j]=temp[start+j];
        j++;
    }
    printf("FLOATING POINT INTEGER %s\n",floatToken);
    
    
    free(floatToken);
    
    return count;
 }
//Prints out an octal integer token
 int getOctalInteger(char* temp, int start){
     int x = start;
     int count = 0;
     for(;x<strlen(temp);++x){
         if(temp[x]=='0'||temp[x]=='1'||temp[x]=='2'||temp[x]=='3'||temp[x]=='4'||temp[x]=='5'||temp[x]=='6'||temp[x]=='7'){
             count+=1;
         }
         else{
             break;
         }
     }
     char* octalToken;
     octalToken = (char*)malloc(sizeof(char)*count);
     int j = 0;
     while(j<count){
         octalToken[j]=temp[start+j];
         j++;
     }
     printf("OCTAL INTEGER %s\n",octalToken);
     free(octalToken);
     return count;
 }
//Prints out a decimal integer
 int getDecimalInteger(char* temp, int start){
     int x = start;
     int count = 0;
     for(;x<strlen(temp);++x){
         if(temp[x]=='0'||temp[x]=='1'||temp[x]=='2'||temp[x]=='3'||temp[x]=='4'||temp[x]=='5'||temp[x]=='6'||temp[x]=='7'||temp[x]=='8'||temp[x]=='9'){
             count+=1;
         }
         else{
             break;
         }
     }
     char* decimalToken;
     decimalToken = (char*)malloc(sizeof(char)*count);
     int j = 0;
     while(j<count){
         decimalToken[j]=temp[start+j];
         j++;
     }
     printf("DECIMAL INTEGER %s\n",decimalToken);
     free(decimalToken);
     return count;
 }

int main(int argc, char* argv[])
{
    int i;
   char* str = argv[1];
   
   
   while(i<strlen(str)){
       // printf("The length of the string is %ld",strlen(str));
     //  printf("index %d\n",i);
       //If we find digit, we go down the digit branch for its possbile returns
       if(isdigit(str[i])){
           
           
           
           //Look for a floating point
           if(i!=strlen(str)-1&&(str[i+1]=='.')){
            i+= getFloatingdecimalToken(str,i);
           // printf("The new Value of I %d\n",i);
           }
           //Look for a Hexidecimal
           else if(i!=strlen(str)-1&&str[i]=='0'&&(str[i+1]=='x'||str[i+1]=='X')){
            i+= getHexidecimalToken(str,i);
           }
           //Look for an octal integer
           else if(str[i]=='0'&&(i<strlen(str)&&str[i+1]=='1'||str[i+1]=='2'||str[i+1]=='3'||str[i+1]=='4'||str[i+1]=='5'||str[i+1]=='6'||str[i+1]=='7')){
               i+= getOctalInteger(str,i);

           }
           //Look for a decimal Integer
          else if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'){
                i+=getDecimalInteger(str,i);
           }

       }
       //Look for a word
        if(isalpha(str[i])){
           i+=getWordToken(str,i);   
         //  printf("index %d\n",i);   
       }
       //Operators
     //  printf("The letter at the first index is %c\n", str[i]);
       switch(str[i]){
           
           case '|':{
               if(i<strlen(str)-1&&(str[i+1]=='='||str[i+1]=='|')){
                   if(str[i+1]=='='){
                       printf("bitwise OR equals: |=\n");
                       i+=1;
                   }
                   else if(str[i+1]== '|'){
                       printf("logical OR: ||\n");
                       i+=1;
                   }
                   
               }
               else if(str[i]=='|'){
                       printf("bitwise OR |\n");
                   }
               break;
           }
           
           
           case '(' :{
            printf("left parenthesis: (\n");
           
           break;

           }
            case ')' :{
            printf("right parenthesis: )\n");
           
           break;

           }
           case '[' :{
            printf("left bracket: [\n");
           
           break;

           }
           case ']' :{
            printf("right bracket: ]\n");
           
           break;

           }
           case '.' :{
            printf("structure member: .\n");
           
           break;

           }
           //Branches from -
           case '-':{

               if(i<strlen(str)-1&&(str[i+1]=='>'||str[i+1]=='-'||str[i+1]=='=')){
                   if(str[i+1]=='>'){
                       printf("structure pointer: ->\n");
                       i+=1;
                   }
                   else if(str[i+1]=='-'){
                       printf("decrement: --\n");
                       i+=1;
                   }
                   else if(str[i+1]=='='){
                       printf("minus equals: -=\n");
                       i+=1;
                   }
                  

               }
               else if(str[i]=='-'){
                      printf("minus/subtract operator: -\n");
                       
                   }
                   break;
           }
           //Branches from +
           case '+':{
               if(i<strlen(str)-1&&(str[i+1]=='+'||str[i+1]=='=')){
                   if(str[i+1]=='+'){
                       printf("increment: ++\n");
                       i+=1;
               }
                   
                   else if(str[i+1]=='='){
                       printf("plus equals: +=\n");
                       i+=1;
                   }

               }
               else if(str[i]=='+'){
                   printf("addition: +\n");
               }
               break;
           }
           //Branches from >
          
           case '>':{
               if(i<strlen(str-2)&&(str[i+1]=='>'&&str[i+2]=='=')){
                   if(str[i+1]=='>'&&str[i+2]=='='){
                       printf("shift right equals: >>=\n");
                       
                       i+=2;
                      
                   }
               }
                if(i<strlen(str)-1&&(str[i+1]=='>'||str[i+1]=='=')){
                   if(str[i+1]=='>'){
                       printf("shift right: >>\n");
                       i+=1;
                   }
                   else if(str[i+1]=='='){
                       printf("greater than or equal test: >=\n");
                       i+=1;
                   }
                   
               }
               else if(str[i]=='>'){
                   printf("greater than test: >\n");

               }
               
                break;
           }
           //Branches from <
           case '<':{
               
              if(i<strlen(str)-2&&(str[i+1]=='<'&&str[i+2]=='=')){
                   if(str[i+1]=='<'&&str[i+2]=='='){
                       printf("shift left equals: <<=\n");
                       i+=2;
                   }
                  // printf("The index is %d, the character is %c and the size is %ld\n",i,str[i],strlen(str));
               }
             
               if(i<strlen(str)-1&&(str[i+1]=='<'||str[i+1]=='=')){
                  //  printf("The index is %d, the character is %c and the size is %ld\n",i,str[i],strlen(str));
                   if(str[i+1]=='<'){
                       printf("shift left: <<\n");
                       i+=1;
                   }
                   else if(str[i+1]=='='){
                       printf("less than or equal test: <=\n");
                       i+=1;
                   }
                  // printf("The leng of the string is %ld\n",strlen(str)-1);
                   
               }
               else if (str[i]=='<'){
                   printf("less than test: <\n");

               }
               break;
           }
           case '&':{
               if(i<strlen(str)-1&&(str[i+1]=='&'||str[i+1]=='=')){
                   if(str[i+1]=='&'){
                       printf("logical AND &&\n");
                       i+=1;
                   }
                   else if(str[i+1]=='='){
                       printf("bitwise AND equals &=\n");
                       i+=1;
                   }
               }
               else if(str[i]=='&'){
                   printf("AND/address operator &\n");

               }
               break;
           }
           case '=':{
               if(i<strlen(str)-1&&str[i+1]=='='){
                   
                       printf("equality test ==\n");
                       i+=1;
                   
               }
                else if(str[i]=='='){
                   printf("assignment =\n");
               }
               break;
           }
            case '%':{
               if(i<strlen(str)-1&&str[i+1]=='='){
                   printf("mod equals %%=");
               }


               break;
           }
           case ',':{
               if(str[i]==','){
                   printf("comma ,\n");
               }


               break;
           }
           case '*':{
               if(str[i]=='*'){
                   printf("multiply/dereference operator *\n");
               }


               break;
           }
           case '?':{
               if(str[i]=='?'){
                   printf("conditional true ?\n");
               }


               break;
           }
           case ':':{
               if(str[i]==':'){
                   printf("conditional false ;\n");
               }


               break;
           }
           case '^':{
               if(str[i]=='^'){
                   printf("bitwise XOR ^\n");
               }
               


               break;
           }
           case '~':{
               if(str[i]=='~'){
                   printf("1s complement ~\n");
               }
           }
        

           
           case '!':{
               if(str[i]=='!'){
                   printf("bitwise XOR !\n");
               }


               break;
           }

           i++;
           

       }
       
       i+=1;

     
   }
   return 0;
}
