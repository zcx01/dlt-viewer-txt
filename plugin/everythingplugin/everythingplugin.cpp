/**
 * @licence app begin@
 * Copyright (C) 2011-2012  BMW AG
 *
 * This file is part of COVESA Project Dlt Viewer.
 *
 * Contributions are licensed to the COVESA Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \file EverythingPlugin.cpp
 * For further information see http://www.covesa.global/.
 * @licence end@
 */

#include <QtGui>

#include "everythingplugin.h"


EverythingPlugin::EverythingPlugin() {
    form = NULL;
    dltFile = 0;
}

EverythingPlugin::~EverythingPlugin() {
}

QString EverythingPlugin::name()
{
    return plugin_name_displayed;
}

QString EverythingPlugin::pluginVersion(){
    return DLT_VIEWER_PLUGIN_VERSION;
}

QString EverythingPlugin::pluginInterfaceVersion(){
    return PLUGIN_INTERFACE_VERSION;
}

QString EverythingPlugin::description() {
    return QString();
}

QString EverythingPlugin::error() {
    return QString();
}

bool EverythingPlugin::loadConfig(QString /*filename*/) {
    return true;
}

bool EverythingPlugin::saveConfig(QString /*filename*/) {
    return true;
}

QStringList EverythingPlugin::infoConfig() {
    return QStringList();
}

QWidget* EverythingPlugin::initViewer() {
    form = new Everything::Form();
    return form;
}

void EverythingPlugin::selectedIdxMsgDecoded(int , QDltMsg &msg){
    /* Show Decoded output */
}

void EverythingPlugin::selectedIdxMsg(int index, QDltMsg &msg) {

}


void EverythingPlugin::initFileStart(QDltFile *file)
{
    dltFile = file;
    //qDebug() << "Activate plugin" << plugin_name_displayed <<  DLT_VIEWER_PLUGIN_VERSION;
}

void EverythingPlugin::initMsg(int /*index*/, QDltMsg & /*msg*/){
}

void EverythingPlugin::initMsgDecoded(int , QDltMsg &){
//empty. Implemented because derived plugin interface functions are virtual.
}

void EverythingPlugin::initFileFinish(){
}

void EverythingPlugin::updateFileStart(){
//empty. Implemented because derived plugin interface functions are virtual.
}

void EverythingPlugin::updateMsg(int /*index*/, QDltMsg &/*msg*/){
}

void EverythingPlugin::updateMsgDecoded(int , QDltMsg &){
//empty. Implemented because derived plugin interface functions are virtual.
}

void EverythingPlugin::updateFileFinish(){
}

QString EverythingPlugin::stringToHtml(QString str)
{
    str = str.replace("<","&#60;");
    str = str.replace(">","&#62;");

    return str;
}


#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
Q_EXPORT_PLUGIN2(EverythingPlugin, EverythingPlugin);
#endif
