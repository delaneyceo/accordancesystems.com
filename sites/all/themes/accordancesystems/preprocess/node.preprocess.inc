<?php

/**
 * Implements hook_preprocess_node().
 */
function accordancesystems_preprocess_node(&$variables) {
  $variables['print_node_anchor'] = TRUE;

  switch ($variables['type']) {
    case 'dealer':
      if ($variables['elements']['#view_mode'] == 'dealer_listing') {
        $variables['print_node_anchor'] = FALSE;
        // Change the url title to be consistent.
        if (!empty($variables['content']['field_dealer_url'])) {
          $variables['content']['field_dealer_url'][0]['#element']['title'] = 'Visit website';
        }
      }
      break;
    case 'araid_controller_display':
      if ($variables['elements']['#view_mode'] == 'featured_slide') {
        $variables['print_node_anchor'] = FALSE;
      }
      break;
  }
}
