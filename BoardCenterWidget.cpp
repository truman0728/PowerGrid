#include "BoardCenterWidget.h"

BoardCenterWidget::BoardCenterWidget() {
	
	// Init components
	gridLayout = new QGridLayout();
	centerStackedWidget = new QStackedWidget();
	modeWidget = new QWidget();
	vBoxLayout = new QVBoxLayout();
	powerPlantsModeButton = new QPushButton();
	mapModeButton = new QPushButton();
	resourceMarketModeButton = new QPushButton();
	overviewModeButton = new QPushButton();
	powerPlantModeWidget = new PowerPlantModeWidget();
	resourceMarketModeWidget = new ResourceMarketModeWidget();
	overviewModeWidget = new OverviewModeWidget();

	// Configure components
	modeWidget->setObjectName("modeWidget");
	powerPlantsModeButton->setObjectName("boardModeButton");
	mapModeButton->setObjectName("boardModeButton");
	resourceMarketModeButton->setObjectName("boardModeButton");
	overviewModeButton->setObjectName("boardModeButton");

	// Set layout
	setLayout(gridLayout);
	modeWidget->setLayout(vBoxLayout);

	// Add to stack
	powerPlantModeWidgetIndex = centerStackedWidget->addWidget(powerPlantModeWidget);
	resourceMarketModeWidgetIndex = centerStackedWidget->addWidget(resourceMarketModeWidget);
	overviewModeWidgetIndex = centerStackedWidget->addWidget(overviewModeWidget);

	// Default active
	centerStackedWidget->setCurrentIndex(powerPlantModeWidgetIndex);

	// Connect buttons
	connect(powerPlantsModeButton, SIGNAL(clicked()), this, SLOT(onPowerPlantMode()));
	connect(resourceMarketModeButton, SIGNAL(clicked()), this, SLOT(onResourceMarketMode()));
	connect(overviewModeButton, SIGNAL(clicked()), this, SLOT(onOverviewMode()));

	// Add components
	vBoxLayout->addWidget(mapModeButton, 0);
	vBoxLayout->addWidget(powerPlantsModeButton, 0);
	vBoxLayout->addWidget(resourceMarketModeButton, 0);
	vBoxLayout->addWidget(overviewModeButton, 0);
	gridLayout->addWidget(centerStackedWidget, 0, 0);
	gridLayout->addWidget(modeWidget, 0, 1, Qt::AlignRight);
}

BoardCenterWidget::~BoardCenterWidget() {
	delete powerPlantsModeButton;
	delete mapModeButton;
	delete resourceMarketModeButton;
	delete overviewModeButton;
	delete powerPlantModeWidget;
	delete resourceMarketModeWidget;
	delete overviewModeWidget;
	delete vBoxLayout;
	delete modeWidget;
	delete centerStackedWidget;
	delete gridLayout;
}

/**********
 * SLOTS
 **********/

void BoardCenterWidget::onMapMode() {
	qDebug("Switching to map mode");
}

void BoardCenterWidget::onResourceMarketMode() {
	qDebug("Switching to resource market mode");
	centerStackedWidget->setCurrentIndex(resourceMarketModeWidgetIndex);
}

void BoardCenterWidget::onPowerPlantMode() {
	qDebug("Switching to power plant mode");
	centerStackedWidget->setCurrentIndex(powerPlantModeWidgetIndex);
}

void BoardCenterWidget::onOverviewMode() {
	qDebug("Switching to overview mode");
	centerStackedWidget->setCurrentIndex(overviewModeWidgetIndex);
}

/// This method is required when Q_OBJECT is added
/// Without this method, the CSS will not be applied
void BoardCenterWidget::paintEvent(QPaintEvent *pe) {
	QStyleOption o;
	o.initFrom(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
};