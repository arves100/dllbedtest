/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: Common
	File: Cache.cpp
	Desc: Implementation of a small cache
*/
#include "StdAfx.h"
#include "Cache.hpp"

CElement::CElement() {}
CElement::~CElement()
{
	Destroy();
}

void CElement::Destroy()
{
	for (auto& it : m_vecData)
		DestroyObject(it);

	m_vecData.clear();
}

void CElement::Add(uint64_t nId, void* pData)
{
	m_vecData.insert_or_assign(nId, pData);
}

void CElement::Remove(uint64_t nId)
{
	auto it = m_vecData.find(nId);

	if (it != m_vecData.end())
	{
		DestroyObject(std::pair<uint64_t, void*>(it->first, it->second));
		m_vecData.erase(it);
	}
}

void* CElement::Get(uint64_t nId)
{
	auto it = m_vecData.find(nId);

	if (it == m_vecData.end())
		return nullptr;

	return it->second;
}

void CElement::DestroyObject(std::pair<uint64_t, void*> it) {}

uint64_t CElement::GetType()
{
	return ElementTypes::None;
}

//-------------------------------------------------------------------------

void CLibraryElement::DestroyObject(std::pair<uint64_t, void*> it)
{
	if (it.second)
	{
		FreeLibrary(reinterpret_cast<HMODULE>(it.second));
		it.second = nullptr;
		it.first = 0;
	}
}

uint64_t CLibraryElement::GetType()
{
	return ElementTypes::Library;
}

//-------------------------------------------------------------------------


CCache::CCache() {}
CCache::~CCache()
{
	Destroy();
}

void CCache::Destroy()
{
	for (auto& it : m_mapCaches)
	{
		delete it.second;
	}

	m_mapCaches.clear();
}

void CCache::Add(uint64_t nId, CElement* pElem)
{
	auto it = m_mapCaches.find(nId);

	if (it != m_mapCaches.end())
	{
		delete (*it).second;
	}

	m_mapCaches.insert_or_assign(nId, pElem);
}

CElement* CCache::Get(uint64_t nCacheId)
{
	auto it = m_mapCaches.find(nCacheId);

	if (it == m_mapCaches.end())
		return nullptr;

	return (*it).second;
}

void* CCache::GetElement(uint64_t nCacheId, uint64_t nElementId)
{
	auto cE = Get(nCacheId);
	if (!cE)
		return nullptr;

	return cE->Get(nElementId);
}

std::shared_ptr<CCache> CCache::Instance()
{
	return m_pInstance;
}

std::shared_ptr<CCache> CCache::m_pInstance = std::make_shared<CCache>();
