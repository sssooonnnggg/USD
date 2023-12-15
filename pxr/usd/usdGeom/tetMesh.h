//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef USDGEOM_GENERATED_TETMESH_H
#define USDGEOM_GENERATED_TETMESH_H

/// \file usdGeom/tetMesh.h

#include "pxr/pxr.h"
#include "pxr/usd/usdGeom/api.h"
#include "pxr/usd/usdGeom/pointBased.h"
#include "pxr/usd/usd/prim.h"
#include "pxr/usd/usd/stage.h"
#include "pxr/usd/usdGeom/tokens.h"

#include "pxr/usd/usd/timeCode.h" 

#include "pxr/base/vt/value.h"

#include "pxr/base/gf/vec3d.h"
#include "pxr/base/gf/vec3f.h"
#include "pxr/base/gf/matrix4d.h"

#include "pxr/base/tf/token.h"
#include "pxr/base/tf/type.h"

PXR_NAMESPACE_OPEN_SCOPE

class SdfAssetPath;

// -------------------------------------------------------------------------- //
// TETMESH                                                                    //
// -------------------------------------------------------------------------- //

/// \class UsdGeomTetMesh
///
/// Encodes a tetrahedral mesh. A tetrahedral mesh is defined as a set of 
/// tetrahedra. Each tetrahedron is defined by a set of 4 points, with the 
/// triangles of the tetrahedron determined from these 4 points as described in 
/// the <b>tetVertexIndices</b> attribute description. The mesh surface faces 
/// are encoded as triangles. Surface faces must be provided for consumers 
/// that need to do surface calculations, such as renderers or consumers using 
/// physics attachments. Both tetrahedra and surface face definitions use 
/// indices into the TetMesh's <b>points</b> attribute, inherited from 
/// UsdGeomPointBased.
///
class UsdGeomTetMesh : public UsdGeomPointBased
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::ConcreteTyped;

    /// Construct a UsdGeomTetMesh on UsdPrim \p prim .
    /// Equivalent to UsdGeomTetMesh::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdGeomTetMesh(const UsdPrim& prim=UsdPrim())
        : UsdGeomPointBased(prim)
    {
    }

    /// Construct a UsdGeomTetMesh on the prim held by \p schemaObj .
    /// Should be preferred over UsdGeomTetMesh(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdGeomTetMesh(const UsdSchemaBase& schemaObj)
        : UsdGeomPointBased(schemaObj)
    {
    }

    /// Destructor.
    USDGEOM_API
    virtual ~UsdGeomTetMesh();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDGEOM_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdGeomTetMesh holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdGeomTetMesh(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDGEOM_API
    static UsdGeomTetMesh
    Get(const UsdStagePtr &stage, const SdfPath &path);

    /// Attempt to ensure a \a UsdPrim adhering to this schema at \p path
    /// is defined (according to UsdPrim::IsDefined()) on this stage.
    ///
    /// If a prim adhering to this schema at \p path is already defined on this
    /// stage, return that prim.  Otherwise author an \a SdfPrimSpec with
    /// \a specifier == \a SdfSpecifierDef and this schema's prim type name for
    /// the prim at \p path at the current EditTarget.  Author \a SdfPrimSpec s
    /// with \p specifier == \a SdfSpecifierDef and empty typeName at the
    /// current EditTarget for any nonexistent, or existing but not \a Defined
    /// ancestors.
    ///
    /// The given \a path must be an absolute prim path that does not contain
    /// any variant selections.
    ///
    /// If it is impossible to author any of the necessary PrimSpecs, (for
    /// example, in case \a path cannot map to the current UsdEditTarget's
    /// namespace) issue an error and return an invalid \a UsdPrim.
    ///
    /// Note that this method may return a defined prim whose typeName does not
    /// specify this schema class, in case a stronger typeName opinion overrides
    /// the opinion at the current EditTarget.
    ///
    USDGEOM_API
    static UsdGeomTetMesh
    Define(const UsdStagePtr &stage, const SdfPath &path);

protected:
    /// Returns the kind of schema this class belongs to.
    ///
    /// \sa UsdSchemaKind
    USDGEOM_API
    UsdSchemaKind _GetSchemaKind() const override;

private:
    // needs to invoke _GetStaticTfType.
    friend class UsdSchemaRegistry;
    USDGEOM_API
    static const TfType &_GetStaticTfType();

    static bool _IsTypedSchema();

    // override SchemaBase virtuals.
    USDGEOM_API
    const TfType &_GetTfType() const override;

public:
    // --------------------------------------------------------------------- //
    // TETVERTEXINDICES 
    // --------------------------------------------------------------------- //
    /// Flat list of the index (into the <b>points<> attribute) of 
    /// each vertex of each tetrahedron in the mesh. Each int4 corresponds to the
    /// indices of a single tetrahedron. Users should set the <b>orientation<>
    /// attribute of UsdGeomPrim accordingly. That is if the <b>orientation<> 
    /// is "rightHanded", the CCW face ordering of a tetrahedron is
    /// [123],[032],[013],[021] with respect to the int4. This results in the
    /// normals facing outward from the center of the tetrahedron. If the
    /// <b>orientation<> attribute is set to "leftHanded" the face ordering of 
    /// the tetrahedron is [321],[230],[310],[120] and the leftHanded CW face 
    /// normals point outward from the center of the tetrahedron. Setting the 
    /// <b>orientation<> attribute to align with the ordering of the int4 for  
    /// the tetrahedrons is the responsibility of the user.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int4[] tetVertexIndices` |
    /// | C++ Type | VtArray<GfVec4i> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Int4Array |
    USDGEOM_API
    UsdAttribute GetTetVertexIndicesAttr() const;

    /// See GetTetVertexIndicesAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDGEOM_API
    UsdAttribute CreateTetVertexIndicesAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // SURFACEFACEVERTEXINDICES 
    // --------------------------------------------------------------------- //
    /// <b>surfaceFaceVertexIndices<> defines the triangle
    /// surface faces indices wrt. <b>points<> of the tetmesh surface. Again 
    /// the <b>orientation<> attribute inherited from UsdGeomPrim should be 
    /// set accordingly. The <b>orientation<> for faces of tetrahedra and  
    /// surface faces must match.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int3[] surfaceFaceVertexIndices` |
    /// | C++ Type | VtArray<GfVec3i> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Int3Array |
    USDGEOM_API
    UsdAttribute GetSurfaceFaceVertexIndicesAttr() const;

    /// See GetSurfaceFaceVertexIndicesAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDGEOM_API
    UsdAttribute CreateSurfaceFaceVertexIndicesAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // ===================================================================== //
    // Feel free to add custom code below this line, it will be preserved by 
    // the code generator. 
    //
    // Just remember to: 
    //  - Close the class declaration with }; 
    //  - Close the namespace with PXR_NAMESPACE_CLOSE_SCOPE
    //  - Close the include guard with #endif
    // ===================================================================== //
    // --(BEGIN CUSTOM CODE)--
    
    /// ComputeSurfaceFaces determines the vertex indices of the surface faces 
    /// from tetVertexIndices. The surface faces are the set of faces that occur 
    /// only once when traversing the faces of all the tetrahedra. The algorithm 
    /// is O(n) in the number of tetrahedra. Method returns false if 
    /// surfaceFaceIndices argument is nullptr and returns true otherwise.
    USDGEOM_API    
    static bool ComputeSurfaceFaces(const UsdGeomTetMesh& tetMesh,
                                    VtVec3iArray* surfaceFaceIndices,
                                    const UsdTimeCode timeCode = UsdTimeCode::Default());     

private:
    // IndexTri is a helper class used by ComputeSurfaceFaces
    class _IndexTri
    {
    public:
        _IndexTri(int fv0, int fv1, int fv2):_unsortedIndices(fv0, fv1, fv2),
                                             _sortedIdx0(fv0),
                                             _sortedIdx1(fv1),
                                             _sortedIdx2(fv2)  
        {
            // _sortedIdx0, _sortedIdx1 and _sortedIdx2 are 
            // sorted indices because order is important when determining
            // face equality.          
            _SortFVIndices(_sortedIdx0,_sortedIdx1,_sortedIdx2);
            // .. and this is a perfect hash for a face, provided
            // there are fewer than 2097152 (2**21) points. But we
            // keep the sorted indices around to resolve collisions
            //
            _hash = _sortedIdx0 << 42 ^ _sortedIdx1 << 21 ^ _sortedIdx2;
        }      

        size_t GetHash() const {
            return _hash;
        }           

        bool operator == (const _IndexTri& other) const {
          // A face is the same as another if the
          // three sorted indices are identical.
          // In practice, this function will only
          // get called for extremely large meshes.
          return (_sortedIdx0 == other._sortedIdx0) &&
                 (_sortedIdx1 == other._sortedIdx1) &&
                 (_sortedIdx2 == other._sortedIdx2);            
        }

        const GfVec3i& GetUnsortedIndices() const {
            return _unsortedIndices;
        }
     
    private:         

        static void _SortFVIndices(size_t& a, size_t& b, size_t& c) {
            if (a > b) {
                std::swap(a, b);
            }
  
            if (a > c) {
                std::swap(a, c);
            }
 
            if (b > c) {
                std::swap(b, c);
            }
        }
        
        // Original unsorted indices
        const GfVec3i _unsortedIndices;

        // Sorted Indices
        size_t _sortedIdx0;
        size_t _sortedIdx1;
        size_t _sortedIdx2;

        // Precomputed hash
        size_t _hash;                                 
    };

    struct _IndexTriHash {
        size_t operator()(const _IndexTri& tri) const
        {
            return tri.GetHash();
        }
    };

    struct _IndexTriEquals {
        bool operator()(const _IndexTri& a, const _IndexTri& b) const
        {
            return a == b;
        }
    };   
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif