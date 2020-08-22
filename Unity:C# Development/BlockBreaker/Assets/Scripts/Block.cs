using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Block : MonoBehaviour
{
    [SerializeField] AudioClip breakSound;
    [SerializeField] GameObject blockSparklesVFX;
    [SerializeField] Sprite[] damageLevels;

    Level level;

    [SerializeField] int timesHit;

    private void Start()
    {
        CountBreakableBlocks();

    }

    private void CountBreakableBlocks()
    {
        level = FindObjectOfType<Level>();
        if (tag == "Breakable")
        {
            level.CountBlocks();
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (tag == "Breakable")
        {
            CheckHits();
        }
    }

    private void CheckHits()
    {
        timesHit++;
        int maxHits = damageLevels.Length + 1;
        if (timesHit >= maxHits)
        {
            DestroyBlock();
        }
        else
        {
            ShowNextHitSprite();
        }
    }

    private void ShowNextHitSprite()
    {
        int spriteIndex = timesHit - 1;
        if (damageLevels[spriteIndex] != null)
        {
            GetComponent<SpriteRenderer>().sprite = damageLevels[spriteIndex];
        }
        else
        {
            Debug.LogError("Block Sprite is missing in Array" + gameObject.name);
        }
            
    }

    private void DestroyBlock()
    {
        AudioSource.PlayClipAtPoint(breakSound, Camera.main.transform.position);
        Destroy(gameObject);
        TriggerSparklesVFX();
        level.BlockDestroyed();
        FindObjectOfType<GameSession>().AddToScore();
        
    }

    private void TriggerSparklesVFX()
    {
        GameObject sparkles = Instantiate(blockSparklesVFX, transform.position, transform.rotation);
        Destroy(sparkles, 2f);
    }
}
