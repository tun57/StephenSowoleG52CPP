#include "EnemyProperties.h"
#include "math.h"
#include "Config.h"


EnemyProperties::EnemyProperties (BaseEngine* pEngine ) 
	: DisplayableObject( pEngine ) 
{

	retreat = false;
}


EnemyProperties::~EnemyProperties(void)
{


}

void EnemyProperties::EnemyUpdate(int targetX, int targetY, int radius) {

	float diff_X = ((targetX - m_iDrawWidth/2) - m_iCurrentScreenX);
	float diff_Y = ((targetY - m_iDrawHeight/2) - m_iCurrentScreenY);
	float z = pow((pow(diff_X,2) + pow(diff_Y,2)), 0.5f);

	if (diff_X != 0 || diff_Y != 0) {

		if (!retreat) {

			m_iCurrentScreenX += ((diff_X/z) * speed);
			m_iCurrentScreenY += ((diff_Y/z) * speed);

		} else {
			
			if (m_iCurrentScreenX > 0 && m_iCurrentScreenX < (BASE_SCREEN_WIDTH - m_iDrawWidth)) {

				m_iCurrentScreenX -= ((diff_X/z) * 1.15);

			} else if (m_iCurrentScreenX < 0 || m_iCurrentScreenX > (BASE_SCREEN_WIDTH - m_iDrawWidth)) {

				m_iCurrentScreenX += ((diff_X/z) * speed);
			}

			if (m_iCurrentScreenY > 0 && m_iCurrentScreenY < (BASE_SCREEN_HEIGHT - m_iDrawHeight)) {

				m_iCurrentScreenY -= ((diff_Y/z) * 1.15);

			} else if (m_iCurrentScreenY < 0 || m_iCurrentScreenY > (BASE_SCREEN_HEIGHT - m_iDrawHeight)) {

				m_iCurrentScreenY += ((diff_Y/z) * speed);
			}
		}
	}

	checkCollisions(targetX, targetY, radius);

	// Ensure that the object gets redrawn on the display, if something changed 
	RedrawObjects();
}

void EnemyProperties::setRetreat(bool retreatSet) {

	retreat = retreatSet;
}

bool EnemyProperties::isRetreating(void) {

	return retreat;
}

void EnemyProperties::checkCollisions(int targetX, int targetY, int radiusy)
{
}

void EnemyProperties::SetSpeed(float speedSet)
{
	speed = speedSet;
}


float EnemyProperties::RandomFloatBetween(float firstNumber, float secondNumber)
{
	float diff = secondNumber - firstNumber;
	return (((float) (rand() % ((unsigned)RAND_MAX + 1)) / RAND_MAX) * diff) + firstNumber;
}
