#include "vista.h"

class ObjectoProp;

Vista::Vista(QGraphicsScene *escena)
    :QGraphicsView(escena)
    ,m_componente(Q_NULLPTR)
    ,m_svgRenderer(Q_NULLPTR)
    ,m_fondo(Q_NULLPTR)
{
}

void Vista::insertarComponentes(QGraphicsScene* m_escena)
{
    this->dibujeFondo(m_escena);
    this->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_svgRenderer = new QSvgRenderer(QString(":/Resources/assets.svg"), this);

    /*m_componente = new ObjetoProp("horca");
    m_componente->setElementId("horca");
    m_componente->setSharedRenderer(m_svgRenderer);
    //m_componente->setScale(5);
    m_escena->addItem(m_componente);*/

    /*m_componente = new ObjetoProp("cabeza");
    m_componente->setElementId("cabeza");
    m_componente->setSharedRenderer(m_svgRenderer);
    m_escena->addItem(m_componente);*/
}

void Vista::dibujeFondo (QGraphicsScene* m_escena){
     QSvgRenderer* svgRenderer = new QSvgRenderer(QString(":/Resources/Fondo.svg"), this);
     m_fondo = new ObjetoProp("background2");
     m_fondo->setSharedRenderer(svgRenderer);
     m_escena->addItem(m_fondo);
     this->fitInView(m_fondo,Qt::KeepAspectRatioByExpanding);
     m_fondo->setZValue(-1);
     m_fondo->setOpacity(1);
}

Vista::~Vista()
{
    delete  m_componente;
    delete  m_svgRenderer;
}
