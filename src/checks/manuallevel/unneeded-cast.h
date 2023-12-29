/*
    SPDX-FileCopyrightText: 2015 Klarälvdalens Datakonsult AB a KDAB Group company info@kdab.com
    Author: Sérgio Martins <sergio.martins@kdab.com>

    SPDX-FileCopyrightText: 2015 Sergio Martins <smartins@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef CLAZY_UNNEEDED_CAST_H
#define CLAZY_UNNEEDED_CAST_H

#include "checkbase.h"

#include <string>

class ClazyContext;
namespace clang
{
class CXXNamedCastExpr;
class CXXRecordDecl;
class Stmt;
} // namespace clang

namespace
{
class CXXNAmedCastExpr;
}

/**
 * Finds redundant casts.
 * See README-unneeded-cast.md for more info.
 */
class UnneededCast : public CheckBase
{
public:
    UnneededCast(const std::string &name, ClazyContext *context);
    void VisitStmt(clang::Stmt *stm) override;

private:
    bool handleNamedCast(clang::CXXNamedCastExpr *);
    bool handleQObjectCast(clang::Stmt *);
    bool maybeWarn(clang::Stmt *, clang::CXXRecordDecl *from, clang::CXXRecordDecl *to, bool isQObjectCast = false);
};

#endif
