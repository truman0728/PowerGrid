#pragma once

#include <QWidget>
#include <vector>
#include "ResourceMarketLevelWidget.h"

class ResourceMarketModeWidget : public QWidget {
public:
	ResourceMarketModeWidget();
	~ResourceMarketModeWidget();
	void Refresh();
private:
	std::vector<ResourceMarketLevelWidget*> resourceMarketLevelwidgets;
	QGridLayout *gridLayout;
};

