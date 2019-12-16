#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<math.h> 
typedef struct SysParameter
{
float V;     // System Voltage
float R1,R2,R3,RLoad;  // Resistance
float I1,I2,I3;   // Cell sourcing currents
}
SysParameter;
SysParameter CurrSysValue(float,float,float,SysParameter);
SysParameter CurrSysValueFOF(float,SysParameter);
SysParameter CurrSysValueOFF(float,SysParameter);
SysParameter CurrSysValueFFO(float,SysParameter);
SysParameter CurrSysValueOOF(float,float,SysParameter);
SysParameter CurrSysValueOFO(float,float,SysParameter);
SysParameter CurrSysValueFOO(float,float,SysParameter);
float dischargeV1(float); 
float dischargeV2(float); 
float dischargeV3(float); 
float a=0.90, b=0.95, c=0.85;  // Discharging rate of the three cells 

int main() 
{ 
SysParameter P,Q;
float B1, B2, B3;
int cycle=0;
printf("\nWelcome to Battery balancing algorithm during the discharge cycle.!!!");
printf("\nSet intial voltages of the cell B1, B2 & B3 (10V-13V in range): "); 
scanf("%f %f %f",&B1,&B2,&B3); 
printf("Set resistor value of R1, R2 & R3(in Kohm): "); 
scanf("%f%f%f",&Q.R1,&Q.R2,&Q.R3); 
printf("Set Load RLoad(in Kohm): "); 
scanf("%f",&Q.RLoad); 
Q.I1=0, Q.I2=0, Q.I3=0; 
while(B1>=6 && B2>=6 && B3>=6) 
{ 
if((B1<B2) && (B1<B3)) 
{ 
    if(fabs(B2-B3)>=1) 
    { 
        while(fabs(B2-B3)>=1 && (B1<B2) && (B1<B3)) 
        { 
            if(B2>B3) 
            { 
            B2=dischargeV2(B2); 
	    P=CurrSysValueFOF(B2,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=OFF, S2=ON, S3=OFF"); 
            } 
            else 
            { 
            B3=dischargeV3(B3); 
	    P=CurrSysValueFFO(B3,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=OFF, S2=OFF, S3=ON"); 
            } 
        } 
    } 
        else if(fabs(B1-B3)>=1 || fabs(B1-B2)>=1) 
        { 
            while((fabs(B1-B3)>=1 || fabs(B1-B2)>=1) && (B1<B2) && (B1<B3)) 
            { 
            B3=dischargeV3(B3); 
            B2=dischargeV2(B2); 
	    P=CurrSysValueFOO(B2,B3,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=OFF, S2=ON, S3=ON"); 
            } 
        } 
        else 
        { 
            while(fabs(B1-B3)<1 && fabs(B2-B3)<1 && fabs(B1-B1)<1) 
            { 
            B3=dischargeV3(B3); 
            B2=dischargeV2(B2); 
            B1=dischargeV1(B1); 
	    P=CurrSysValue(B1,B2,B3,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=ON, S2=ON, S3=ON"); 
            } 
        } 
} 
//----------------------------------------------------------------------------------------------------------- 
else if((B2<B3) && (B2<B1)) 
        if(fabs(B1-B3)>=1) 
    { 
        while(fabs(B1-B3)>=1 && (B2<B3) && (B2<B1)) 
        { 
            if(B1>B3) 
            { 
            B1=dischargeV1(B1); 
	    P=CurrSysValueOFF(B1,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=ON, S2=OFF, S3=OFF"); 
            } 
            else 
            { 
            B3=dischargeV3(B3); 
	    P=CurrSysValueFFO(B3,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=OFF, S2=OFF, S3=ON"); 
            } 
        } 
    } 
        else if(fabs(B2-B3)>=1 || fabs(B2-B1)>=1 ) 
        { 
            while((fabs(B2-B3)>=1 || fabs(B2-B1)>=1 ) && (B2<B3) && (B2<B1)) 
            { 
            B3=dischargeV3(B3); 
            B1=dischargeV1(B1); 
	    P=CurrSysValueOFO(B1,B3,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=ON, S2=OFF, S3=ON");  
            } 
        } 
        else 
        { 
            while(fabs(B1-B3)<1 && fabs(B2-B3)<1 && fabs(B1-B1)<1) 
            { 
            B3=dischargeV3(B3); 
            B2=dischargeV2(B2); 
            B1=dischargeV1(B1); 
	    P=CurrSysValue(B1,B2,B3,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=ON, S2=ON, S3=ON");  
            } 
        } 
    //--------------------------------------------------------------------------------------------------------- 
else 
    //if((B3<B2) && (B3<B1)) 
     if(fabs(B2-B1)>=1) 
    { 
        while(fabs(B2-B1)>=1 && (B3<B2) && (B3<B1)) 
        { 
            if(B2>B1) 
            { 
            B2=dischargeV2(B2); 
	    P=CurrSysValueFOF(B2,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=OFF, S2=ON, S3=OFF");  
            } 
            else 
            { 
            B1=dischargeV1(B1); 
	    P=CurrSysValueOFF(B1,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=ON, S2=OFF, S3=OFF");  
            } 
        } 
    } 
        else if((fabs(B2-B3)>=1 || fabs(B1-B3)>=1 ) && (B3<B2) && (B3<B1)) 
        { 
            while(fabs(B2-B3)>=1 || fabs(B1-B3)>=1 ) 
            { 
            B2=dischargeV2(B2); 
            B1=dischargeV1(B1); 
	    P=CurrSysValueOOF(B1,B2,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=ON, S2=ON, S3=OFF");  
            }
        } 
        else 
        { 
            while(fabs(B1-B3)<1 && fabs(B2-B3)<1 && fabs(B1-B1)<1) 
            { 
            B3=dischargeV3(B3); 
            B2=dischargeV2(B2); 
            B1=dischargeV1(B1); 
	    P=CurrSysValue(B1,B2,B3,Q);
            printf("\nDischarge Cycle %d",++cycle); 
            printf("\nCurrent I1=%.3f, I2=%.3f, I3=%.3f ",P.I1,P.I2,P.I3);
	    printf("\tSystem Voltage=%f",P.V);
            printf("\nVoltageB1=%.3f, B2=%.3f, B3=%.3f",B1,B2,B3);
            printf("\tState S1=ON, S2=ON, S3=ON"); 
            } 
        } 
} 
printf("\nSimulation Stop!!!");   
printf("Discharge Cycle count= %d\n",cycle);
if (cycle==100) exit(1);   
return 0; 

}   

float dischargeV1(float V1)     
{ V1= a * V1;       // Computing voltage B1 after every each discharge cycle (discharging curve assumed linear)
  return V1; } 

float dischargeV2(float V2) 
{ V2= b * V2;  	// Computing voltage B2 after every each discharge cycle
  return V2; } 

float dischargeV3(float V3) 
{ V3= c * V3;	// Computing voltage B3 after every each discharge cycle
 return V3; } 

SysParameter CurrSysValue(float V1,float V2,float V3,SysParameter S) // ON-ON-ON State
{
S.V=(V1/S.R1+V2/S.R2+V3/S.R3)/(1/S.R1+1/S.R2+1/S.R3+1/S.RLoad); // Computing System Voltage
S.I1=(V1-S.V)/S.R1; S.I2=(V2-S.V)/S.R2; S.I3=(V3-S.V)/S.R3;	// Computing cell sourcing current
return S;
}
SysParameter CurrSysValueOOF(float V1,float V2,SysParameter S) // ON-ON-OFF State
{
S.V=(V1/S.R1+V2/S.R2)/(1/S.R1+1/S.R2+1/S.RLoad); 	// Computing System Voltage
S.I1=(V1-S.V)/S.R1; S.I2=(V2-S.V)/S.R2; S.I3=0;		// Computing cell sourcing current
return S;
}
SysParameter CurrSysValueOFO(float V1,float V3,SysParameter S)  // ON-OFF-ON State
{
S.V=(V1/S.R1+V3/S.R3)/(1/S.R1+1/S.R3+1/S.RLoad); 	// Computing System Voltage
S.I1=(V1-S.V)/S.R1; S.I2=0; S.I3=(V3-S.V)/S.R3;		//Computing cell sourcing current
return S;
}
SysParameter CurrSysValueFOO(float V2,float V3,SysParameter S) // OFF-ON-ON state
{
S.V=(V2/S.R2+V3/S.R3)/(1/S.R2+1/S.R3+1/S.RLoad); 	// Computing System Voltage
S.I1=0; S.I2=(V2-S.V)/S.R2; S.I3=(V3-S.V)/S.R3;		//Computing cell sourcing current
return S;
}
SysParameter CurrSysValueFOF(float V2,SysParameter S)  // For OFF-ON-OFF state
{
S.V=(V2/S.R2)/(1/S.R2+1/S.RLoad);		// Computing System Voltage
S.I1=0; S.I2=(V2-S.V)/S.R2; S.I3=0;		//Computing cell sourcing current
return S;
}
SysParameter CurrSysValueOFF(float V1,SysParameter S)  // For ON-OFF-OFF state
{
S.V=(V1/S.R1)/(1/S.R1+1/S.RLoad);		// Computing System Voltage
S.I1=(V1-S.V)/S.R1; S.I2=0; S.I3=0;		//Computing cell sourcing current
return S;
}
SysParameter CurrSysValueFFO(float V3,SysParameter S)  // For OFF-OFF-ON state
{
S.V=(V3/S.R3)/(1/S.R3+1/S.RLoad);		// Computing System Voltage
S.I1=0; S.I2=0; S.I3=(V3-S.V)/S.R3;		//Computing cell sourcing current
return S;
}


