using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIFunctions : MonoBehaviour
{
	public void LoadLevel(string level)
	{
		UnityEngine.SceneManagement.SceneManager.LoadScene (level);
	}
}
