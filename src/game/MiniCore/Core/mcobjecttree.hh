// This file belongs to the "MiniCore" game engine.
// Copyright (C) 2010 Jussi Lind <jussi.lind@iki.fi>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
// MA  02110-1301, USA.
//

#ifndef MCOBJECTTREE_HH
#define MCOBJECTTREE_HH

#include "mcbbox.hh"
#include "mcmacros.hh"
#include "mcobject.hh"

#include <unordered_set>

//! A geometrically structured MCObjectTree used for fast collision detection.
//! The tree stores objects inherited from MCObject -class.
//! A (2d) collision test for a given object can be requested against all
//! objects of a given typeid.
class MCObjectTree
{
public:

    //! Container for objects. There are a lot of inserts/removals so
    //! unordered_set is taken.
    typedef std::unordered_set<MCObject *> ObjectSet;

    //! Constructor.
    //! \param x1,y1,x2,y2 represent the size of the first-level bounding box.
    //! \param leafMaxW,leafMaxH are the maximum dimensions for leaves.
    MCObjectTree(
        MCFloat x1, MCFloat y1, MCFloat x2, MCFloat y2,
        MCUint leafMaxW, MCUint leafMaxH);

    //! Destructor.
    ~MCObjectTree();

    //! Insert an object into the tree (O(1)).
    //! \param object is the object to be inserted.
    void insert(MCObject & object);

    //! Remove an object from the tree (O(1)).
    //! \param object is the object to be removed.
    //! \return true if was removed.
    bool remove(MCObject & object);

    //! Remove all objects.
    void removeAll();

    //! Get objects within given distance.
    void getObjectsWithinDistance(MCFloat x, MCFloat y, MCFloat d, ObjectSet & resultObjs);

    //! Get all objects of given type overlapping given BBox.
    void getObjectsWithinBBox(const MCBBox<MCFloat> & rBBox, ObjectSet & resultObjs);

    //! Get bbox collisions involving the given object
    //! \param object Object to be tested.
    //! \param rVectPObjs Vector in which colliding object are stored.
    //! \param typeId Match MCObjects of given type only.
    void getBBoxCollisions(const MCObject & object, ObjectSet & resultObjs);

    //! Get bounding box
    const MCBBox<MCFloat> & bbox() const;

private:

    DISABLE_COPY(MCObjectTree);
    DISABLE_ASSI(MCObjectTree);

    void getIndexRange(const MCBBox<MCFloat> & bbox);
    void build();
    MCBBox<MCFloat> m_bbox;
    MCUint m_leafMaxW, m_leafMaxH, m_horSize, m_verSize;
    MCUint m_i0, m_i1, m_j0, m_j1;
    MCFloat m_helpHor;
    MCFloat m_helpVer;
    MCObjectTree::ObjectSet * m_matrix;
};

#endif // MCOBJECTTREE_HH

