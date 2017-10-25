#include "SettingsTab.h"

CSettingsTab::CSettingsTab(QWidget *parent /*= nullptr*/) : QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &CSettingsTab::accept);
	connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &CSettingsTab::reject);
}

CSettingsTab::~CSettingsTab()
{
}

int CSettingsTab::GetUpdateInterval() const
{
	return ui.spinBoxUpdate->value();
}

unsigned CSettingsTab::GetIconSize() const
{
	return static_cast<unsigned>(ui.spinBoxSize->value());
}
