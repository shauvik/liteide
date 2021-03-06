/**************************************************************************
** This file is part of LiteIDE
**
** Copyright (c) 2011-2014 LiteIDE Team. All rights reserved.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** In addition, as a special exception,  that plugins developed for LiteIDE,
** are allowed to remain closed sourced and can be distributed under any license .
** These rights are included in the file LGPL_EXCEPTION.txt in this package.
**
**************************************************************************/
// Module: folderproject.cpp
// Creator: visualfc <visualfc@gmail.com>

#include "folderproject.h"
#include <QFileInfo>
//lite_memory_check_begin
#if defined(WIN32) && defined(_MSC_VER) &&  defined(_DEBUG)
     #define _CRTDBG_MAP_ALLOC
     #include <stdlib.h>
     #include <crtdbg.h>
     #define DEBUG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__ )
     #define new DEBUG_NEW
#endif
//lite_memory_check_end

FolderProject::FolderProject(IApplication *app) :
    m_liteApp(app), m_widget(0)
{
    m_widget = new FileSystemWidget(app);
}

FolderProject::~FolderProject()
{
    if (m_widget) {
        delete m_widget;
    }
}

QWidget *FolderProject::widget()
{
    return m_widget;
}

QString FolderProject::name() const
{
    return "FolderProject";
}

QString FolderProject::filePath() const
{
    return m_widget->startPath();
}

QString FolderProject::mimeType() const
{
    return "folder/x-path";
}

void FolderProject::openFolder(const QString &folder)
{
    m_widget->setRootPath(folder);
}

void FolderProject::appendFolder(const QString &folder)
{
    m_widget->addRootPath(folder);
}

void FolderProject::clear()
{
    m_widget->clear();
}

QStringList FolderProject::folderList() const
{
    return m_widget->rootPathList();
}

QStringList FolderProject::fileNameList() const
{
    return QStringList();
}

QStringList FolderProject::filePathList() const
{
    return QStringList();
}

QString FolderProject::fileNameToFullPath(const QString &filePath)
{
    return filePath;
}

QMap<QString,QString> FolderProject::targetInfo() const
{
    return QMap<QString,QString>();
}

void FolderProject::load()
{

}
