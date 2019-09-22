#include "Player.h"
#include <iostream>

Player::Player() {
}

void Player::keyCallback(int key, int action, double time, std::vector<Note>& v, std::vector<Note>& ev) {
	if (action == GLFW_PRESS) {
		if (key == GREEN_CODE) {
			bool found = false;
			for (size_t i = 0; i < v.size(); ++i) {
				if (v.at(i).getHit() && v.at(i).getType() == TAP_G) {
					found = true;
					m_score += 100 * m_mult;
					if (v.at(i).getMilli() != m_past_tap) {
						m_combo++;
						m_past_tap = v.at(i).getMilli();
					}
					v.at(i).click(time);
					break;
				}
			}
			for (size_t j = 0; j < ev.size(); ++j) {
				if (ev.at(j).getHit() && ev.at(j).getType() == SCR_G_START) {
					found = true;
					break;
				}
			}
			if (!found) {
				m_combo = 0;
				m_eu_zone_active = false;
			}
			m_green = true;
		}

		if (key == RED_CODE) {
			bool found = false;
			for (size_t i = 0; i < v.size(); ++i) {
				if (v.at(i).getHit() && v.at(i).getType() == TAP_R) {
					found = true;
					m_score += 100 * m_mult;
					if (v.at(i).getMilli() != m_past_tap) {
						m_combo++;
						m_past_tap = v.at(i).getMilli();
					}
					v.at(i).click(time);
					break;
				}
			}
			if (!found) {
				m_combo = 0;
				m_eu_zone_active = false;
			}
			m_red = true;
			
		}

		if (key == BLUE_CODE) {
			bool found = false;
			for (size_t i = 0; i < v.size(); ++i) {
				if (v.at(i).getHit() && v.at(i).getType() == TAP_B) {
					found = true;
					m_score += 100 * m_mult;
					if (v.at(i).getMilli() != m_past_tap) {
						m_combo++;
						m_past_tap = v.at(i).getMilli();
					}
					v.at(i).click(time);
					break;
				}
			}
			for (size_t j = 0; j < ev.size(); ++j) {
				if (ev.at(j).getHit() && ev.at(j).getType() == SCR_G_START) {
					found = true;
					break;
				}
			}
			if (!found) {
				m_combo = 0;
				m_eu_zone_active = false;
			}
			m_blue = true;
			
		}
		if (key== CROSS_L_CODE) {
			if (m_cross != 0) {
				bool found = false;
				for (size_t i = 0; i < ev.size(); ++i) {
					if (ev.at(i).getHit() && ev.at(i).getType() == CROSS_G) {
						found = true;
						ev.at(i).click(time);
						m_score += 100 * m_mult;
						m_combo++;
						break;
					}
				}
				if (!found) {
					m_combo = 0;
					m_eu_zone_active = false;
				}
			}
			m_cross = 0;
			
		}
		if (key== CROSS_R_CODE) {
			if (m_cross != 2) {
				bool found = false;
				for (size_t i = 0; i < ev.size(); ++i) {
					if (ev.at(i).getHit() && ev.at(i).getType() == CROSS_B) {
						found = true;
						ev.at(i).click(time);
						m_score += 100 * m_mult;
						m_combo++;
						break;
					}
				}
				if (!found) {
					m_combo = 0;
					m_eu_zone_active = false;
				}
			}
			m_cross = 2;
			
		}
		if (key== SCRATCH_UP) {
			bool found = false;
			if (m_green) {
				for (size_t i = 0; i < v.size(); ++i) {
					if (v.at(i).getHit()) {
						int type = v.at(i).getType();
						if (type == SCR_G_UP) {
							found = true;
							v.at(i).click(time);
							m_score += 100 * m_mult;
							m_combo++;
							break;
						}
						else if (type == SCR_G_ANY) {
							found = true;
							v.at(i).click(time);
							m_score += 25 * m_mult;
							m_scr_tick++;
						}
					}
				}
				
			}
			if (m_blue) {
				for (size_t i = 0; i < v.size(); ++i) {
					if (v.at(i).getHit()) {
						int type = v.at(i).getType();
						if (type == SCR_B_UP) {
							found = true;
							v.at(i).click(time);
							m_score += 100 * m_mult;
							m_combo++;
							break;
						}
						else if (type == SCR_B_ANY) {
							found = true;
							v.at(i).click(time);
							m_score += 25 * m_mult;
							m_scr_tick++;
						}
					}
				}
				
			}
			if (!found) {
				m_combo = 0;
				m_eu_zone_active = false;
			}
		}
		if (key== SCRATCH_DOWN) {
			bool found = false;
			if (m_green) {
				for (size_t i = 0; i < v.size(); ++i) {
					if (v.at(i).getHit()) {
						int type = v.at(i).getType();
						if (type == SCR_G_DOWN) {
							found = true;
							v.at(i).click(time);
							m_score += 100 * m_mult;
							m_combo++;
							break;
						}
						else if (type == SCR_G_ANY) {
							found = true;
							v.at(i).click(time);
							m_score += 25 * m_mult;
							m_scr_tick++;
						}
					}
				}
			}
			if (m_blue) {
				for (size_t i = 0; i < v.size(); ++i) {
					if (v.at(i).getHit()) {
						int type = v.at(i).getType();
						if (type == SCR_B_DOWN) {
							found = true;
							v.at(i).click(time);
							m_score += 100 * m_mult;
							m_combo++;
							break;
						}
						else if (type == SCR_B_ANY) {
							found = true;
							v.at(i).click(time);
							m_score += 25 * m_mult;
							m_scr_tick++;
						}
					}
				}
			}
			if (!found) {
				m_combo = 0;
				m_eu_zone_active = false;
			}
			
		}
		if (key == EUPHORIA) {
			if (m_eu_value > 0.0) {
				m_euphoria_active = true;
			}
		}
	}
	else if (action == GLFW_REPEAT) {
	if (key == SCRATCH_UP) {
		bool found = false;
		if (m_green) {
			for (size_t i = 0; i < v.size(); ++i) {
				if (v.at(i).getHit()) {
					int type = v.at(i).getType();
					if (type == SCR_G_UP) {
						found = true;
						v.at(i).click(time);
						m_score += 100 * m_mult;
						m_combo++;
						break;
					}
					else if (type == SCR_G_ANY) {
						found = true;
						v.at(i).click(time);
						m_score += 25 * m_mult;
						m_scr_tick++;
					}
				}
			}

		}
		if (m_blue) {
			for (size_t i = 0; i < v.size(); ++i) {
				if (v.at(i).getHit()) {
					int type = v.at(i).getType();
					if (type == SCR_B_UP) {
						found = true;
						v.at(i).click(time);
						m_score += 100 * m_mult;
						m_combo++;
						break;
					}
					else if (type == SCR_B_ANY) {
						found = true;
						v.at(i).click(time);
						m_score += 25 * m_mult;
						m_scr_tick++;
					}
				}
			}

		}
		if (!found) {
			m_combo = 0;
			m_eu_zone_active = false;
		}
	}
	if (key == SCRATCH_DOWN) {
		bool found = false;
		if (m_green) {
			for (size_t i = 0; i < v.size(); ++i) {
				if (v.at(i).getHit()) {
					int type = v.at(i).getType();
					if (type == SCR_G_DOWN) {
						found = true;
						v.at(i).click(time);
						m_score += 100 * m_mult;
						m_combo++;
						break;
					}
					else if (type == SCR_G_ANY) {
						found = true;
						v.at(i).click(time);
						m_score += 25 * m_mult;
						m_scr_tick++;
					}
				}
			}
		}
		if (m_blue) {
			for (size_t i = 0; i < v.size(); ++i) {
				if (v.at(i).getHit()) {
					int type = v.at(i).getType();
					if (type == SCR_B_DOWN) {
						found = true;
						v.at(i).click(time);
						m_score += 100 * m_mult;
						m_combo++;
						break;
					}
					else if (type == SCR_B_ANY) {
						found = true;
						v.at(i).click(time);
						m_score += 25 * m_mult;
						m_scr_tick++;
					}
				}
			}
		}
		if (!found) {
			m_combo = 0;
			m_eu_zone_active = false;
		}

	}
}
	else if (action == GLFW_RELEASE) {
		if (key== CROSS_L_CODE && m_cross == 0) {
			bool found = false;
			for (size_t i = 0; i < ev.size(); ++i) {
				int type = ev.at(i).getType();
				if (ev.at(i).getHit()) {
					if (type == CROSS_C || type == CROSS_B) {
						if (type == CROSS_C) {
							ev.at(i).click(time);
							m_score += 100 * m_mult;
							m_combo++;
						}
						found = true;
						break;
					}
				}
			}
			if (!found) {
				m_combo = 0;
				m_eu_zone_active = false;
			}
			m_cross = 1;
			
		}
		if (key== CROSS_R_CODE && m_cross == 2) {
			bool found = false;
			for (size_t i = 0; i < ev.size(); ++i) {
				int type = ev.at(i).getType();
				if (ev.at(i).getHit()) {
					if (type == CROSS_C || type == CROSS_G) {
						if (type == CROSS_C) {
							ev.at(i).click(time);
							m_score += 100 * m_mult;
							m_combo++;
						}
						found = true;
						break;
					}
				}
			}
			if (!found) {
				m_combo = 0;
				m_eu_zone_active = false;
			}
			m_cross = 1;

		}
		if (key== GREEN_CODE) {
			m_green = false;
			 
		}
		if (key== RED_CODE) {
			m_red = false;
			 
		}
		if (key== BLUE_CODE) {
			m_blue = false;
			 
		}
		if (key== SCRATCH_UP) {
			m_scr_up = false;
			 
		}
		if (key== SCRATCH_DOWN) {
			m_scr_down = false;
			 
		}
	}

	if (m_combo >= 24)m_mult = 4;
	else if (m_combo >= 16 && m_combo < 24) m_mult = 3;
	else if (m_combo >= 8 && m_combo < 16) m_mult = 2;
	else m_mult = 1;

	if (m_euphoria_active) {
		m_double_mult = true;
	}
	else {
		m_double_mult = false;
	}

	if (m_double_mult)m_mult *= 2;

	if (m_scr_tick >= 4) {
		m_scr_tick = 0;
		m_combo++;
	}
	
}

void Player::tick(double time) {
	if (m_euphoria_active) {
		if (m_eu_value < 0.0)m_euphoria_active = false;
		else {
			double dt = time - m_lastTime;
			float de = (dt * m_genBpm) / (60 * 16);
			m_eu_value -= de;
		}
	}
	m_lastTime = time;
}

void Player::pollState(Generator &g){
    if(g.m_combo_reset == true){
        m_combo = 0;
		m_eu_zone_active = false;
    }
	if (g.m_eu_start) {
		m_eu_zone_active = true;
	}
	if (g.m_eu_check && m_eu_zone_active) {
		if(m_eu_value < 3.0)m_eu_value += 1.0;
	}
	m_genBpm = g.m_bpm;
}

int Player::getScore(){
    return m_score;
}

int Player::getCombo(){
    return m_combo;
}

int Player::getMult(){
    return m_mult;
}

int Player::getCross() {
	return m_cross;
}

bool Player::getRedClicker() {
	return m_red;
}

bool Player::getGreenClicker() {
	return m_green;
}

bool Player::getBlueClicker() {
	return m_blue;
}

float Player::getEuValue() {
	return m_eu_value;
}

bool Player::getEuActive() {
	return m_euphoria_active;
}
bool Player::getEuZoneActive() {
	return m_eu_zone_active;
}

Player::~Player() {
    //dtor
}