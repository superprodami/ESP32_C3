#ifndef __OLED_H
#define __OLED_H

/*表情库*/
//extern const unsigned char gImage_disdain1[1030],gImage_disdain2[1030],gImage_disdain3[1030],gImage_disdain4[1030],gImage_disdain5[1030],gImage_disdain6[1030],gImage_disdain7[1030],gImage_disdain8[1030],gImage_disdain9[1030],gImage_disdain10[1030],gImage_disdain11[1030],gImage_disdain12[1030],gImage_disdain13[1030],gImage_disdain14[1030];

void oled_init(void);
void oled_weather(void);

void emoji_normal(void);
void emoji_angry(void);
void emoji_sad();
void emoji_happy();


#endif
