#include "NoteModel.h"

NoteModel::NoteModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_notes.append(Note{"Welcome", "This is your first note in Qt6!"});
    m_notes.append(Note{"To Do", "Buy milk, eggs, and coffee."});
}

int NoteModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_notes.count();
}

QVariant NoteModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
        
    if (index.row() < 0 || index.row() >= m_notes.count())
        return QVariant();

    // Get the specific note
    const Note &note = m_notes[index.row()];

    // Return the specific piece of data requested
    if (role == TitleRole)
        return note.title;

    else if (role == ContentRole)
        return note.content;

    return QVariant();
}

QHash<int, QByteArray> NoteModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[ContentRole] = "content";
    return roles;
}

void NoteModel::addNote(const QString &title, const QString &content)
{
    beginInsertRows(QModelIndex(), m_notes.count(), m_notes.count());
    
    m_notes.append(Note{title, content});
    
    endInsertRows();
}

void NoteModel::removeNote(int index)
{
    if (index < 0 || index >= m_notes.count())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    
    m_notes.removeAt(index);
    
    endRemoveRows();
}