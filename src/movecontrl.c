/*
void Rbt_Init(void)
{
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(15));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(160));
	HAL_Delay(100);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(167));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(20));
	HAL_Delay(100);
}
uint16_t angle(uint8_t angle)
{
	return angle*2000/180+500;
}
void Rbt_attention(void)
{
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90));
	HAL_Delay(100);
}
void move_forward(void)
{
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(135));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(45));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(45));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(135));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90));

	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(135));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(45));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(45));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(135));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90));
	HAL_Delay(move_delay);
}

void move_behind(void)
{
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(45));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(135));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(135));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(45));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90));

	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(45));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(135));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(135));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(45));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90));
	HAL_Delay(move_delay);
}

void move_right(void)
{
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(45));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(45));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(135));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(135));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90));
	HAL_Delay(move_delay);
}

void move_left(void)
{
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(135));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(135));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(45));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(45));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90));
	HAL_Delay(move_delay);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90));
	HAL_Delay(move_delay);
}

void move_swing(void)
{
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(130));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(130));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(50));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(50));
	HAL_Delay(200);
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(50));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(50));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(130));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(130));
	HAL_Delay(200);
}

void move_stretch(void){
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90));
	if(TIM2->CCR1<angle(155) && TIM2->CCR3>angle(25)){
		for(uint8_t i=0;i<70;i++){
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90+i));
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90-i));
			HAL_Delay(move_speed);
		}
		HAL_Delay(1000);
		for(uint8_t i=0;i<70;i++){
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(160-i));
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(20+i));
			HAL_Delay(move_speed);
		}
		for(uint8_t i=0;i<65;i++){
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90+i));
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90-i));
			HAL_Delay(move_speed);
		}
		for(uint8_t i=0;i<20;i++){
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90-i));
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90+i));
			HAL_Delay(move_speed);
		}
		HAL_Delay(1000);
		__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(140));
		HAL_Delay(1000);
		__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(178));
		HAL_Delay(500);
		__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(140));
		HAL_Delay(500);
		__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(178));
		HAL_Delay(500);
		__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(140));
		HAL_Delay(500);
		__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(70));
	}
}

void move_sleep(void){
	if(TIM2->CCR3<angle(160) && TIM2->CCR1>angle(20)){
		for(uint8_t i=0;i<75;i++){
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90-i));
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90+i));
			HAL_Delay(move_speed);
		}
	}
	if(TIM2->CCR2<angle(160) && TIM2->CCR4>angle(20)){
		for(uint8_t i=0;i<75;i++){
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90+i));
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90-i));
			HAL_Delay(move_speed);
		}
	}

}
void move_dance(void)
{
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90));
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90));
	if(TIM2->CCR1<angle(160) && TIM2->CCR2<angle(160)){//当在目标位置之外，则执行
		for(uint8_t i=0;i<75;i++){
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(90+i));
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(90+i));
			HAL_Delay(move_speed);
		}
		for(uint8_t i=0;i<75;i++){
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,angle(165-i));
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2,angle(165-i));
			HAL_Delay(move_speed);
		}
	}
	if(TIM2->CCR3>angle(20) && TIM2->CCR4>angle(20)){
		for(uint8_t i=0;i<75;i++){
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(90-i));
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(90-i));
			HAL_Delay(move_speed);
		}
		for(uint8_t i=0;i<75;i++){
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3,angle(15+i));
			__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4,angle(15+i));
			HAL_Delay(move_speed);
		}
	}
}
*/