/*
	FileName : MiscFnx.c
	Description : 
		General purpose functions.

  	Created on 2006.12.23 by ZZP
	Revision History:

*/

#include "includes.h"

#include "MiscFnx.h"


const uint16_t CRCTable[] = 
      {
        0x0000,0x1021,0x2042,0x3063,0x4084,0x50A5,0x60C6,0x70E7,0x8108,0x9129,0xA14A,0xB16B,0xC18C,0xD1AD,0xE1CE,0xF1EF,
        0x1231,0x0210,0x3273,0x2252,0x52B5,0x4294,0x72F7,0x62D6,0x9339,0x8318,0xB37B,0xA35A,0xD3BD,0xC39C,0xF3FF,0xE3DE,
        0x2462,0x3443,0x0420,0x1401,0x64E6,0x74C7,0x44A4,0x5485,0xA56A,0xB54B,0x8528,0x9509,0xE5EE,0xF5CF,0xC5AC,0xD58D,
        0x3653,0x2672,0x1611,0x0630,0x76D7,0x66F6,0x5695,0x46B4,0xB75B,0xA77A,0x9719,0x8738,0xF7DF,0xE7FE,0xD79D,0xC7BC,
        0x48C4,0x58E5,0x6886,0x78A7,0x0840,0x1861,0x2802,0x3823,0xC9CC,0xD9ED,0xE98E,0xF9AF,0x8948,0x9969,0xA90A,0xB92B,
        0x5AF5,0x4AD4,0x7AB7,0x6A96,0x1A71,0x0A50,0x3A33,0x2A12,0xDBFD,0xCBDC,0xFBBF,0xEB9E,0x9B79,0x8B58,0xBB3B,0xAB1A,
        0x6CA6,0x7C87,0x4CE4,0x5CC5,0x2C22,0x3C03,0x0C60,0x1C41,0xEDAE,0xFD8F,0xCDEC,0xDDCD,0xAD2A,0xBD0B,0x8D68,0x9D49,
        0x7E97,0x6EB6,0x5ED5,0x4EF4,0x3E13,0x2E32,0x1E51,0x0E70,0xFF9F,0xEFBE,0xDFDD,0xCFFC,0xBF1B,0xAF3A,0x9F59,0x8F78,
        0x9188,0x81A9,0xB1CA,0xA1EB,0xD10C,0xC12D,0xF14E,0xE16F,0x1080,0x00A1,0x30C2,0x20E3,0x5004,0x4025,0x7046,0x6067,
        0x83B9,0x9398,0xA3FB,0xB3DA,0xC33D,0xD31C,0xE37F,0xF35E,0x02B1,0x1290,0x22F3,0x32D2,0x4235,0x5214,0x6277,0x7256,
        0xB5EA,0xA5CB,0x95A8,0x8589,0xF56E,0xE54F,0xD52C,0xC50D,0x34E2,0x24C3,0x14A0,0x0481,0x7466,0x6447,0x5424,0x4405,
        0xA7DB,0xB7FA,0x8799,0x97B8,0xE75F,0xF77E,0xC71D,0xD73C,0x26D3,0x36F2,0x0691,0x16B0,0x6657,0x7676,0x4615,0x5634,
        0xD94C,0xC96D,0xF90E,0xE92F,0x99C8,0x89E9,0xB98A,0xA9AB,0x5844,0x4865,0x7806,0x6827,0x18C0,0x08E1,0x3882,0x28A3,
        0xCB7D,0xDB5C,0xEB3F,0xFB1E,0x8BF9,0x9BD8,0xABBB,0xBB9A,0x4A75,0x5A54,0x6A37,0x7A16,0x0AF1,0x1AD0,0x2AB3,0x3A92,
        0xFD2E,0xED0F,0xDD6C,0xCD4D,0xBDAA,0xAD8B,0x9DE8,0x8DC9,0x7C26,0x6C07,0x5C64,0x4C45,0x3CA2,0x2C83,0x1CE0,0x0CC1,
        0xEF1F,0xFF3E,0xCF5D,0xDF7C,0xAF9B,0xBFBA,0x8FD9,0x9FF8,0x6E17,0x7E36,0x4E55,0x5E74,0x2E93,0x3EB2,0x0ED1,0x1EF0
      };
      
// 2000?1?1?00:00:00????:???2099?
const uint32_t Minute_Year[] =
      {
       0,525600,1051200,1576800,2102400,2629440,3155040,3680640,4206240,
       4733280,5258880,5784480,6310080,6837120,7362720,7888320,8413920,
       8940960,9466560,9992160,10517760,11044800,11570400,12096000,12621600,
       13148640,13674240,14199840,14725440,15252480,15778080,16303680,16829280,
       17356320,17881920,18407520,18933120,19460160,19985760,20511360,21036960,
       21564000,22089600,22615200,23140800,23667840,24193440,24719040,25244640,
       25771680,26297280,26822880,27348480,27875520,28401120,28926720,29452320,
       29979360,30504960,31030560,31556160,32083200,32608800,33134400,33660000,
       34187040,34712640,35238240,35763840,36290880,36816480,37342080,37867680,
       38394720,38920320,39445920,39971520,40498560,41024160,41549760,42075360,
       42602400,43128000,43653600,44179200,44706240,45231840,45757440,46283040,
       46810080,47335680,47861280,48386880,48913920,49439520,49965120,50490720,
       51017760,51543360,52068960
      };
	  
//?????1?00:00:00????????
const uint32_t Minute_Month_LeapYear[] =
      {
       0,44640,86400,131040,174240,218880,262080,306720,
       351360,394560,439200,482400
      };
//??????1?00:00:00????????
const uint32_t Minute_Month_NormalYear[] =
      {
        0,44640,84960,129600,172800,217440,260640,305280,
        349920,393120,437760,480960
      };
//???????00:00:00????????
const uint32_t Minute_Date[] =
      {
        0,1440,2880,4320,5760,7200,8640,10080,11520,12960,14400,15840,
        17280,18720,20160,21600,23040,24480,25920,27360,28800,30240,
        31680,33120,34560,36000,37440,38880,40320,41760,43200
      };
//??????????00:00:00????
const uint32_t Minute_Hour[] =
      {
        0,1440,2880,4320,5760,7200,8640,10080,11520,12960,14400,15840,17280,
        18720,20160,21600,23040,24480,25920,27360,28800,30240,31680,33120
      };
////////////////////////////////////////////////////////////////////////////////////////
// second
////////////////////////////////////////////////////////////////////////////////////////
//?2000??2099?:??1?1??? 2000?1?1?00:00:00 ???
const uint32_t Seconds_Years_From2000[] = {
	
        0UL, 31622400UL, 63158400UL, 94694400UL, 126230400UL, 157852800UL, 189388800UL, 220924800UL, 252460800UL, 284083200UL, 
        315619200UL, 347155200UL, 378691200UL, 410313600UL, 441849600UL, 473385600UL, 504921600UL, 536544000UL, 568080000UL, 599616000UL, 
        631152000UL, 662774400UL, 694310400UL, 725846400UL, 757382400UL, 789004800UL, 820540800UL, 852076800UL, 883612800UL, 915235200UL, 
        946771200UL, 978307200UL, 1009843200UL, 1041465600UL, 1073001600UL, 1104537600UL, 1136073600UL, 1167696000UL, 1199232000UL, 1230768000UL, 
        1262304000UL, 1293926400UL, 1325462400UL, 1356998400UL, 1388534400UL, 1420156800UL, 1451692800UL, 1483228800UL, 1514764800UL, 1546387200UL, 
        1577923200UL, 1609459200UL, 1640995200UL, 1672617600UL, 1704153600UL, 1735689600UL, 1767225600UL, 1798848000UL, 1830384000UL, 1861920000UL, 
        1893456000UL, 1925078400UL, 1956614400UL, 1988150400UL, 2019686400UL, 2051308800UL, 2082844800UL, 2114380800UL, 2145916800UL, 2177539200UL, 
        2209075200UL, 2240611200UL, 2272147200UL, 2303769600UL, 2335305600UL, 2366841600UL, 2398377600UL, 2430000000UL, 2461536000UL, 2493072000UL, 
        2524608000UL, 2556230400UL, 2587766400UL, 2619302400UL, 2650838400UL, 2682460800UL, 2713996800UL, 2745532800UL, 2777068800UL, 2808691200UL, 
        2840227200UL, 2871763200UL, 2903299200UL, 2934921600UL, 2966457600UL, 2997993600UL, 3029529600UL, 3061152000UL, 3092688000UL, 3124224000UL};

//????1?00:00:00???1?1?00:00:00???
const uint32_t Seconds_Months_FromLeapYear[] = {
	
        0L, 2678400L, 5184000L, 7862400L, 10454400L, 13132800L, 15724800L, 18403200L, 21081600L, 23673600L, 26352000L, 28944000L};

//????1?00:00:00???1?1?00:00:00???
const uint32_t Seconds_Months_FromNormalYear[] = {
	
        0L, 2678400L, 5097600L, 7776000L, 10368000L, 13046400L, 15638400L, 18316800L, 20995200L, 23587200L, 26265600L, 28857600L};

//???????00:00:00???1?00:00:00???
const uint32_t Seconds_Days_FromThisMonth[] = {
	
        0L, 86400L, 172800L, 259200L, 345600L, 432000L, 518400L, 604800L, 691200L, 777600L, 
        864000L, 950400L, 1036800L, 1123200L, 1209600L, 1296000L, 1382400L, 1468800L, 1555200L, 1641600L, 
        1728000L, 1814400L, 1900800L, 1987200L, 2073600L, 2160000L, 2246400L, 2332800L, 2419200L, 2505600L, 
        2592000L};

//????????????00:00:00???
const uint32_t Seconds_Hours_FromThisDay[] = {
	
        0L, 3600L, 7200L, 10800L, 14400L, 18000L, 21600L, 25200L, 28800L, 32400L, 
        36000L, 39600L, 43200L, 46800L, 50400L, 54000L, 57600L, 61200L, 64800L, 68400L, 
        72000L, 75600L, 79200L, 82800L};

      
      
uint16_t Calc_CRCByte(uint8_t *Buf, uint16_t Len)
{
  uint16_t crc = 0,value;
  
  do 
  {
    value = *Buf++;
    crc = ((crc << 8) ^ CRCTable[((crc >> 8) ^ value) & 0xFF]);
  }while (--Len);
  
  return (crc);
}

uint16_t Calc_CRCByte_Continue(uint8_t *Buf, uint16_t Len, uint16_t last_crc)
{
	uint16_t crc = last_crc, value;
  
	do 
	{
		value = *Buf++;
		crc = ((crc << 8) ^ CRCTable[((crc >> 8) ^ value) & 0xFF]);
	}while (--Len);
  
	return (crc);
}


uint16_t Calc_CRCWord(uint16_t *Data, uint16_t DataBits, uint16_t TotBytes)
{
  uint16_t crc;
  uint16_t temp, temp1, temp2;
  
  if (DataBits == 16)//16Bits word
  {
    crc = 0;
	temp = TotBytes >> 1;
	do
	{
      temp1 = *Data & 0xFF;
	  temp2 = *Data >> 8;
	  Data++;
      crc = ((crc << 8) ^ CRCTable[((crc >> 8) ^ temp1) & 0xFF]);
	  crc = ((crc << 8) ^ CRCTable[((crc >> 8) ^ temp2) & 0xFF]);
	}while (--temp);
    if (TotBytes & 0x01)
	  crc = ((crc << 8) ^ CRCTable[((crc >> 8) ^ (*Data)) & 0xFF]);
  }
  else if (DataBits == 8)
	crc = Calc_CRCByte((uint8_t *)Data, TotBytes);
  
  return (crc);
}


__inline void IncIndex(uint16_t *Index, uint16_t Step, uint16_t Mask)
{
	/*Index += Step;
	if (*Index > Mask)
		*Index -= (Mask + 1);*/
	uint16_t tmp;

	tmp = *Index;
	tmp += Step;
	if (tmp > Mask)
		tmp -= (Mask + 1);
	*Index = tmp;
}


uint32_t GetTimeToMinutes(uint8_t *Tm, uint8_t *Date)
{
	uint32_t tmp;
	uint16_t temp;
  
	if (Date[3] == 0)///Year
		tmp = Minute_Month_NormalYear[Date[1] - 1] + Minute_Date[Date[2] - 1] + 
				Minute_Hour[Tm[0]] + Tm[1];
	else
	{
		temp = Date[3] - ((Date[3] >> 2) << 2);
		if (temp == 0)//??
			tmp = Minute_Year[Date[3]] + Minute_Month_LeapYear[Date[1]] +
					Minute_Date[Date[2] - 1] + Minute_Hour[Tm[0]] + Tm[1];
		else
			tmp = Minute_Year[Date[3]] + Minute_Month_NormalYear[Date[1] - 1] +
					Minute_Date[Date[2] - 1] + Minute_Hour[Tm[0]] + Tm[1];
	}
	return(tmp);
}

uint32_t GetTimeToSeconds(uint8_t *Tm, uint8_t *Date)
{
	uint32_t tmp;
	uint16_t temp;
  
	temp = Date[3] - ((Date[3] >> 2) << 2);
	if (temp == 0)//??
		tmp = Seconds_Months_FromLeapYear[Date[1] - 1];
	else
		tmp = Seconds_Months_FromNormalYear[Date[1] - 1];
	temp = (uint16_t)Tm[1] * 60;
	tmp += (Seconds_Years_From2000[Date[3]] + 
			Seconds_Days_FromThisMonth[Date[2] - 1] +
			Seconds_Hours_FromThisDay[Tm[0]] + temp + Tm[2]);
  
	return(tmp);
}












