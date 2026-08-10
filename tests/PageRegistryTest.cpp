#include "PageRegistry.h"

#include <QString>

int main()
{
    const QString path = QStringLiteral("All Control Panel Items/Getting Started");
    if (PageRegistry::pathFor(PageId::GettingStarted) != path)
        return 1;
    if (PageRegistry::idForPath(path) != PageId::GettingStarted)
        return 2;

    // Existing routes must continue to round-trip after adding the new page.
    const QString existing = PageRegistry::pathFor(PageId::Personalization);
    if (existing.isEmpty()
        || PageRegistry::idForPath(existing) != PageId::Personalization)
        return 3;
    return 0;
}
