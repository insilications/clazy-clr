/*
    SPDX-FileCopyrightText: 2015 Klarälvdalens Datakonsult AB a KDAB Group company info@kdab.com
    Author: Sérgio Martins <sergio.martins@kdab.com>

    SPDX-FileCopyrightText: 2015 Sergio Martins <smartins@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef DETACHING_BASE_H
#define DETACHING_BASE_H

#include "checkbase.h"

#include <map>
#include <string>
#include <vector>

class ClazyContext;

namespace clang
{
class CXXMethodDecl;
}

/**
 * Base class for checks that look for detachments.
 */
class DetachingBase : public CheckBase
{
public:
    explicit DetachingBase(const std::string &name, ClazyContext *context, Options = Option_None);

protected:
    enum DetachingMethodType { DetachingMethod, DetachingMethodWithConstCounterPart };

    bool isDetachingMethod(clang::CXXMethodDecl *, DetachingMethodType = DetachingMethod) const;
};

#endif
